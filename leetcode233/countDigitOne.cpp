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
	int countDigitOne(int n) {
		if (n <= 0) return 0;
		string s = "";
		while (n) {
			char c = '0' + n % 10;
			s = c + s;
			n /= 10;
		}
		int len = s.length();
		int arr[10];
		arr[0] = 0;
		for (int i = 1; i < 10; i++) {
			arr[i] = arr[i - 1] * 10 + pow(10, i - 1);
		}
		int arr1[10];
		arr1[0] = 0;
		for (int i = 1; i < 10; i++) {
			arr1[i] = arr[i - 1] + pow(10, i - 1);
		}
		int ans = 0;
		for (int i = 0; i < len; i++) {
			int k = s[i] - '0';
			if (k == 1) {
				int num = 0;
				for (int j = i + 1; j < len; j++) {
					num = num * 10 + (s[j] - '0');
				}
				ans += (1 + num + arr[len - 1 - i]);
			}
			else if (k == 0){
				continue;
			}
			else ans += (arr1[len - i] + (k - 1) * arr[len - 1 - i]);
		}
		return ans;
	}
};

int main(void) {
	Solution so;
	//1000 272
	cout << so.countDigitOne(9) << endl;;
	cout << so.countDigitOne(99) << endl;;
	cout << so.countDigitOne(998) << endl;;
	cout << so.countDigitOne(999) << endl;;
	cout << so.countDigitOne(1000) << endl;;
	cout << so.countDigitOne(9999) << endl;;
	cout << so.countDigitOne(10000) << endl;;
	//for (int i = 0; i <= 1000;i++) cout << i<<" "<<so.countDigitOne(i) << endl;
	return 0;
}