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
	int isPalindrome(string s) {
		int size = s.size();
		for (int i = 0; i < size / 2; i++) {
			if (s[i] != s[size - 1 - i]) return 0;
		}
		return 1;
	}
	void partition(string& s, int cur, int *arr, vector<vector<string>>& ans){
		if (cur >= n) return;
		if (arr[cur] == -1) {
			for (int i = 1; i + cur <= n; i++) {
				if (isPalindrome(s.substr(cur, i))) {
					partition(s, cur + i, arr, ans);
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
	vector<vector<string>> partition(string s) {
		vector<vector<string>> v;
		n = s.length();
		if (!n) return v;
		int *arr = new int[n];
		memset(arr, -1, n*sizeof(int));
		vector<vector<string>> ans;
		for (int i = 0; i < n; i++){
			vector<string> vec; ans.push_back(vec);
		}
		partition(s, 0, arr, ans);
		for (auto x : ans[0]) {
			vector<string> v1;
			int len = x.length();
			for (int i = 0; i < len; i++){
				int pre = i;
				while (i < len&&x[i] != ' ') i++;
				v1.push_back(x.substr(pre, i - pre));
			}
			v.push_back(v1);
		}
		return v;
	}

	void update_arr(int cur, vector<vector<int>>& arr, string& s) {
		int l = cur - 1, r = cur + 1;
		while (l >= 0 && r < n && (s[l] == s[r])) { if(r > arr[l].back()) arr[l].push_back(r); l--, r++; }
		//arr[l + 1] = max(arr[l + 1], r - 1);
		if (r - 1 > arr[l + 1].back()) arr[l + 1].push_back(r - 1);
		if (cur == n - 1) return;
		l = cur; r = cur + 1;
		while (l >= 0 && r < n && (s[l] == s[r])) { if (r > arr[l].back()) arr[l].push_back(r); l--, r++; }
		if (l != cur) {
			if (r - 1 > arr[l + 1].back())	 arr[l + 1].push_back(r - 1);
		}
	}
	void minCut(int& ans, vector<vector<int>>& arr, int idx, int num, int record[]) {
		int size = arr[idx].size();
		int temp = n - 1;
		if (arr[idx].back() == n - 1) {
			record[idx] = 0; return;
		}
		for (int i = 0; i < size; i++) {
			if (record[arr[idx][i] + 1] == -1) {
				minCut(ans, arr, arr[idx][i] + 1, num + 1, record);	
			}
			temp = min(temp, 1 + record[arr[idx][i] + 1]);
		}
		record[idx] = temp;
	}
	int minCut(string s) {
		n = s.length();
		int ans = n - 1;
		vector < vector<int>> arr;
		for (int i = 0; i < n; i++) {
			vector<int> v; v.push_back(i); arr.push_back(v);
		}
		for (int i = 0; i < n; i++)
			update_arr(i, arr, s);
		int record[10000];
		memset(record, -1, n*sizeof(int));
		minCut(ans, arr, 0, 0, record);
		return record[0];
	}
private:
	int n;
};
int main(void) {
	Solution so;
	//abccbaabcc
	//aaabaa
	printf("%d\n", so.minCut("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"));
	return 0;
}