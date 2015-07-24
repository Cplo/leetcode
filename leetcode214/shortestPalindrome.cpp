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
	string shortestPalindrome(string s) {
		string s1;
		string ans;
		for (int i = 0; i < s.length(); i++) {
			s1 += "#"; s1 += s[i];
		}
		s1 += "#";
		int mx = 0, id = 0;
		int p[100000];
		int j, k;
		int n = s1.size();
		for (int i = 0; i <= n / 2; i++)
		{
			if (i < mx){
				j = 2 * id - i;
				if (j - p[j] > id - p[id]) p[i] = p[j];
				else {
					p[i] = p[j];
					while (i - p[i] >= 0 && i + p[i]<s1.length() && (s1[i + p[i]] == s1[i - p[i]]))
					{
						p[i]++;
					}
					if (p[i] > p[id]){
						id = i; mx = i + p[i] - 1;
					}
				}
			}
			else{
				p[i] = 1;
				while (i - p[i] >= 0 && i + p[i]<s1.length() && (s1[i + p[i]] == s1[i - p[i]]))
				{
					p[i]++;
				}
				if (p[i] > p[id]){
					id = i; mx = i + p[i] - 1;
				}
			}
		}
		
		for (int i = n / 2; i >= 0; i--)	{
			if (i - p[i] + 1 == 0) {
				string str = s1.substr(i + p[i]);
				for (auto x : str) s1 = x + s1;
				for (auto x : s1) if (x != '#') ans += x;
				return ans;
			}
		}
	}
};

int main(void)	{
	Solution so;
	cout << so.shortestPalindrome("") << endl;
	return 0;
}