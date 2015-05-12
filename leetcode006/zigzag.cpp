#include<iostream>
using namespace std;
#include<string>
#include<vector>
class Solution {
public:
	string convert(string s, int nRows) {
		if (nRows == 1)return s;
		string ans;
		vector<char> *array=new vector<char>[nRows];
		int j=0;
		int flag = 1;
		for (int i = 0; i < s.length(); i++)
		{
			array[j].push_back(s[i]);
			if (flag)	{ if (j == nRows - 1) { j--; flag = 0; } else j++; }
			else	{ if (j == 0){ j++; flag = 1; } else j--; }
		}
		for (int i = 0; i < nRows; i++)
		{
			for (int j = 0; j < array[i].size(); j++)
			{
				ans+=array[i][j];
			}
		}
		return ans;
	}
};
int main()
{
	Solution so;
	cout << so.convert("AB", 1) << endl;
	return 0;
}