#include<iostream>
using namespace std;
#include<string>
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		string s1 ;
		int ans=0;
		int count=0;
		int idx;
		for (int i = 0; i < s.length(); i++)
		{
			if ((idx = s1.find(s[i], 0)) == string::npos)
			{
				s1 += s[i];
				count++;
			}
			else
			{
				if (count>ans) ans = count;
				s1 = s1.substr(idx + 1) + s[i];
				count = s1.length();
			}
		}
		return count > ans ? count : ans;
	}
};

int main()
{
	Solution so;
	cout << so.lengthOfLongestSubstring("bpfbhmipx")<<endl;
	return 0;
}