#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<map>
#include<string.h>
#include<string>
#include<queue>

class Solution {
public:
	//»ØËÝ·¨
	vector<vector<string> > solveNQueens(int n) {
		vector<vector<string>> ans;
		int *c = new int[n];
		int *zvis = new int[2 * n];
		int *fvis = new int[2 * n];
		int i;
		for (i = 0; i < n; i++){
			c[i] = i;
		}
		
		do{
			memset(zvis, 0, 2 * n*sizeof(int));
			memset(fvis, 0, 2 * n*sizeof(int));
			for (i = 0; i < n; i++){
				if (zvis[c[i] - i + n] || fvis[c[i] + i]) break;
				else{ zvis[c[i] - i + n] = 1; fvis[c[i] + i] = 1; }
			}
			if (i == n){
				vector<string> v;
				for (int j = 0; j < n; j++){
					string s(n, '.');
					s[c[j]] = 'Q';
					v.push_back(s);
				}
				ans.push_back(v);
			}
		} while (next_permutation(c, c + n));
		return ans;
	}
};

int main(void){
	Solution so;
	vector<vector<string>> ans = so.solveNQueens(8);
	for (auto i : ans){
		for (auto j : i){
			cout << j << endl;
		}
		cout << endl;
	}
	return 0;
}