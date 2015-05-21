#include<iostream>
#include<vector>
#include<string>
#include<string.h>
using namespace std;

class Solution {
public:
	bool recursion(vector<vector<char>>& board, string word, int i, int j, int cur, int arr[]) {
		if (word[cur] == board[i][j]) {
			cur++;
			if (cur == len) return true;
			arr[i*n + j] = 1;
			if (i + 1 < m && (!arr[(i+1)*n+j]) && recursion(board, word, i + 1, j, cur, arr)) return true;
			if (i - 1 >= 0 && (!arr[(i - 1)*n + j]) && recursion(board, word, i - 1, j, cur, arr)) return true;
			if (j + 1 < n && (!arr[i*n + j + 1]) && recursion(board, word, i, j + 1, cur, arr)) return true;
			if (j - 1 >= 0 && (!arr[i*n + j - 1]) && recursion(board, word, i, j - 1, cur, arr)) return true;
			arr[i*n + j] = 0;
		}
		return false;
	}
	bool exist(vector<vector<char>>& board, string word) {
		if (word.empty()) return true;
		if (board.empty()) return false;
		m = board.size();
		n = board[0].size();
		int *arr = new int[m*n];
		memset(arr, 0, m*n*sizeof(int));
		len = word.length();
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][j] == word[0]) {
					if (1 == len) return true;
					arr[i*n + j] = 1;
					if (i + 1 < m && recursion(board, word, i + 1, j, 1, arr)) return true;
					if (i - 1 >= 0 && recursion(board, word, i - 1, j, 1, arr)) return true;
					if (j + 1 < n && recursion(board, word, i, j + 1, 1, arr)) return true;
					if (j - 1 >= 0 && recursion(board, word, i, j - 1, 1, arr)) return true;
					arr[i*n + j] = 0;
				}
			}
		}
		return false;
	}
private:
	int m, n, len;
};

int main(void)	{
	Solution so;
	vector<vector<char>> board;
	char ch[][5] = { "ABCE", 
					 "SFCS", 
					 "ADEE" };// ABCE
	for (int i = 0; i < 3; i++) {
		vector<char> v(ch[i], ch[i] + 4);
		board.push_back(v);
	}
	cout << so.exist(board, "") << endl;
	return 0;
}