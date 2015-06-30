#include<cstdio>
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
	/*bool wordBreak(string& s, unordered_set<string>& wordDict, int cur, int *arr) {
		if (cur >= n) return true;
		if (arr[cur] == -1) {
			for (int i = 1; i + cur <= n; i++) {
				if ((wordDict.find(s.substr(cur, i)) != wordDict.end()) && wordBreak(s, wordDict, cur + i, arr)){
					arr[cur] = 1; return true;
				}
			}
			arr[cur] = 0;
		}
		return arr[cur];
	}
	bool wordBreak(string s, unordered_set<string>& wordDict) {
		n = s.length();
		if (!n) return true;
		int *arr = new int[n];
		memset(arr, -1, n*sizeof(int));
		return wordBreak(s, wordDict, 0, arr);
	}
	*/
	void wordBreak(string& s, unordered_set<string>& wordDict, int cur, int *arr, vector<vector<string>>& ans) {
		if (cur >= n) return;
		if (arr[cur] == -1) {
			for (int i = 1; i + cur <= n; i++) {
				if (wordDict.find(s.substr(cur, i)) != wordDict.end()) {
					wordBreak(s, wordDict, cur + i, arr, ans);
					if (cur + i >= n || arr[cur + i]) {
						arr[cur] = 1;
						if (cur + i < n && arr[cur + i]) for (auto k : ans[cur + i]) {
							ans[cur].push_back(s.substr(cur, i) + " " + k);
						}
						else{
							ans[cur].push_back(s.substr(cur, i));
						}
					}
				}
			}
			if (arr[cur] == -1) arr[cur] = 0;
		}
	}
	vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
		vector<string> v;
		n = s.length();
		if (!n) return v;
		int *arr = new int[n];
		memset(arr, -1, n*sizeof(int));
		vector<vector<string>> ans;
		for (int i = 0; i < n; i++){
			vector<string> vec; ans.push_back(vec);
		}
		wordBreak(s, wordDict, 0, arr, ans);
		return ans[0];
	}
private:
	int n;
}; 
int main(void)	{
	Solution so;
	string str[] = { "a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa" };
	unordered_set<string> u_set(str,str+10);
	so.wordBreak("baaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", u_set);
	//printf("%d\n", so.wordBreak("l", u_set));
	return 0;
}