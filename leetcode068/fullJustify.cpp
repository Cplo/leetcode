#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<map>
#include<string.h>
#include<string>
#include<queue>
#include<float.h>

class Solution {
public:
	vector<string> fullJustify(vector<string>& words, int maxWidth) {
		vector<string> ans;
		if (words.empty()) return ans;
		int n = words.size();
		int sum = 0;
		int start = 0;
		int end=-1;
		int space;
		int evenspace;
		for (int i = 0; i < n; ) {
			if (!sum)
			{
				sum += words[i].size(); start = i;
			}
			else
				sum += (words[i].size() + 1);
			if (sum >= maxWidth){
				string str;
				end = sum > maxWidth ? i - 1 : i;
				int flag = 0;
				if (sum > maxWidth) { sum -= (words[i].size()+1); flag = 1; }
				space = maxWidth - (sum - (end - start));
				for (int m = start; m <= end - 1; m++){
					evenspace = ceil((double)space / (end - m));
					string s(evenspace,' ');
					s = words[m] + s;
					space -= evenspace; 
					str += s;
				}
				str += words[end];
				string s1(maxWidth - str.length(), ' ');
				str += s1;
				ans.push_back(str);
				sum = 0;
				if (flag){
					continue;
				}
			}
			i++;
		}
		if (end < n-1) {
			string str;
			for (int m = start; m < n-1; m++){
				str += (words[m] + " ");
			}
			str += words[n - 1];
			string s(maxWidth - str.length(), ' ');
			str += s;
			ans.push_back(str);
		}
		return  ans;
	}

};

int main(void){
	string s[] = { "Don't", "go", "around", "saying",
		"the", "world", "owes", "you", "a", "living;",
		"the", "world", "owes", "you", "nothing;", "it",
		"was", "here", "first." };
	vector<string> v(s, s + 19);
	Solution so;
	v = so.fullJustify(v,30);
	for (auto u : v){
		cout << u << endl;
	}
	return 0;
}