#include<iostream>
#include<vector>
#include<string>
#include<string.h>
#include<algorithm>
#include<map>
#include<float.h>
#include<stack>
#include<math.h>
#include<queue>
#include<unordered_set>
using namespace std;

class Solution {
public:
	int compareVersion(string version1, string version2) {
		int len1 = version1.length();
		int len2 = version2.length();
		int i = 0, j = 0;
		while (i < len1&&j < len2) {
			int start1 = i, start2 = j;
			i++; j++;
			while (i < len1&&version1[i] >= '0'&&version1[i] <= '9') i++;
			while (j < len2&&version2[j] >= '0'&&version2[j] <= '9') j++;
			int num1, num2;
			sscanf(version1.substr(start1, i - start1).c_str(), "%d", &num1);
			sscanf(version2.substr(start2, j - start2).c_str(), "%d", &num2);
			if (num1 > num2) return 1;
			if (num1 < num2) return -1;
			i++; j++;
		}
		if (i >= len1&&j >= len2) return 0;
		if (i < len1) {
			while (i < len1 && (version1[i] == '.' || version1[i] == '0')) i++;
			if (i<len1) return 1;
			return 0;
		}
		if (j < len2) {
			while (j < len2 && (version2[j] == '.' || version2[j] == '0')) j++;
			if(j<len2) return -1;
			return 0;
		}
	}
};

int main(void){
	Solution so;
	cout << so.compareVersion("1.1.0","1.1") << endl;
	return 0;
}