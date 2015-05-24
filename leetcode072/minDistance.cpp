//Runtime: 24 ms
#include<iostream>

using namespace std;

#include<string>
#include<algorithm>
#include<float.h>

int step[1000][1000];
class Solution {
public:
	int min_dis(int cur1, int cur2) {
		if (cur2 == 1) {
			if (!cur1) step[cur1][cur2] = 1;
			else if (word1.substr(0,cur1).find(word2[cur2 - 1])!=string::npos) step[cur1][cur2] = cur1 - 1;
			else step[cur1][cur2] = cur1;
			return step[cur1][cur2];
		}
		if (cur1 == 1) {
			if (!cur2) step[cur1][cur2] = 1;
			else if (word2.substr(0, cur2).find(word1[cur1 - 1]) != string::npos) step[cur1][cur2] = cur2 - 1;
			else step[cur1][cur2] = cur2;
			return step[cur1][cur2];
		}
		int a = n1;
		//插入模式
		if (step[cur1][cur2 - 1] == -1) step[cur1][cur2 - 1] = min_dis(cur1, cur2 - 1);
		a = min(a, 1 + step[cur1][cur2 - 1]);
		//删除模式
		if (step[cur1 - 1][cur2] == -1) step[cur1-1][cur2] = min_dis(cur1-1, cur2);
		a = min(a, 1 + step[cur1-1][cur2]);
		//替换模式
		if (step[cur1 - 1][cur2 - 1] == -1) step[cur1 - 1][cur2 - 1] = min_dis(cur1 - 1, cur2 - 1);
		if (word1[cur1 - 1] == word2[cur2 - 1]) a = min(a, step[cur1 - 1][cur2 - 1]);
		else a = min(a, 1+step[cur1 - 1][cur2 - 1]);
		step[cur1][cur2] = a;
		return a;
	}
	int minDistance(string word1, string word2) {
		int n1 = word1.length();
		int n2 = word2.length();
		if (!n1 || !n2) return max(n1, n2);
		if (n2 > n1) swap(word1, word2);
		this->n1 = n1 = word1.length();
		this->n2 = n2 = word2.length();
		this->word1 = word1;
		this->word2 = word2;
		for (int i = 0; i <= n1+1; i++) {
			for (int j = 0; j <= n2 + 1; j++) {
				step[i][j] = -1;
			}
		}
		ans = this->n1;
		min_dis(n1, n2);
		return step[n1][n2];
	}
private:
	int n1,n2;
	int ans;
	string word1, word2;
};

int main(void) {
	Solution so;
	cout << so.minDistance("a","ab") << endl;
	return 0;
}