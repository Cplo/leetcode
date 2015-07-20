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
//X X X X
//X O O X
//X X O X
//X O X X
class Solution {
public:
	void solve(vector<vector<char>>& board, int **board_temp, int i, int j) {
		queue<int> row; queue<int> column;
		row.push(i); column.push(j);
		board_temp[i][j] = 0;
		while (!row.empty()) {
			int r = row.front(); int c = column.front(); row.pop(); column.pop();
			if (r - 1 >= 0 && (board[r - 1][c] == 'O') && board_temp[r - 1][c]) { board_temp[r - 1][c] = 0; row.push(r - 1); column.push(c); }
			if (r + 1 < n && (board[r + 1][c] == 'O') && board_temp[r + 1][c]) { board_temp[r + 1][c] = 0; row.push(r + 1); column.push(c); }
			if (c - 1 >= 0 && (board[r][c - 1] == 'O') && board_temp[r][c - 1]) { board_temp[r][c - 1] = 0; row.push(r); column.push(c - 1); }
			if (c + 1 < m && (board[r][c + 1] == 'O') && board_temp[r][c + 1]) { board_temp[r][c + 1] = 0; row.push(r); column.push(c + 1); }
			//cout << r <<" " <<c << endl;
		}
	}
	void solve(vector<vector<char>>& board) {
		n = board.size();
		if (!n) return;
		m = board[0].size();
		int **board_temp = new int*[n];
		for (int i = 0; i < n;i++) {
			board_temp[i] = new int[m];
			memset(board_temp[i], 1, m*sizeof(int));
		}
		for (int i = 0; i < m; i++)
			if ((board[0][i] == 'O') && board_temp[0][i]) {
				solve(board, board_temp, 0, i);
			}
		for (int i = 0; i < m; i++)
			if ((board[n - 1][i] == 'O') && board_temp[n - 1][i]) {
				solve(board, board_temp, n-1, i);
			}
		for (int i = 0; i < n; i++)
			if ((board[i][0] == 'O') && board_temp[i][0]) {
				solve(board, board_temp, i, 0);
			}
		for (int i = 0; i < n; i++)
			if ((board[i][m - 1] == 'O') && board_temp[i][m - 1]) {
				solve(board, board_temp, i,  m - 1);
			}
		for (int i = 1; i < n - 1; i++) {
			for (int j = 1; j < m - 1; j++) {
				if ((board[i][j] == 'O') && board_temp[i][j]) board[i][j] = 'X';
			}
		}
	}
private:
	int n, m;
};

int main(void) {
	/*char arr[][7] = { 
		"OXOOOX", 
		"OOXXXO", 
		"XXXXXO", 
		"OOOOXX", 
		"XXOOXO", 
		"OOXXXX" };*/
	char arr[][251] = {
		"OOOOOOOOXOOOOOXOOOOO", 
		"OOOOOOOXOOOOOOOOOOOO", 
		"XOOXOXOOOOXOOXOOOOOO", 
		"OOOOOOOOOOOOOOOOOXXO", 
		"OXXOOOOOOXOOOOOOOOOO", 
		"OOOOXOOOOOOXOOOOOXXO", 
		"OOOOOOOXOOOOOOOOOOOO", 
		"OOOOOOOOOOOOOXOOOOOO", 
		"OOOOOOOOOOOOOOOOOOXO", 
		"OOOOOXOOOOOOOOOOOOOO", 
		"OOOOOOOOXOOOOOOOOOOO", 
		"OOOOXOOOOXOOOOOOOOOO", 
		"OOOOOOOOXOOOOOOOOOOO", 
		"XOOOOOOOOXXOOOOOOOOO", 
		"OOOOOOOOOOOXOOOOOOOO", 
		"OOOOXOOOOOOOOXOOOOOX", 
		"OOOOOXOOOOOOOOOXOXOO", 
		"OXOOOOOOOOOOOOOOOOOO", 
		"OOOOOOOOXXOOOXOOXOOX", 
		"OOOOOOOOOOOOOOOOOOOO" };
	vector<vector<char>> board;
	for (int i = 0; i < 20; i++) {
		vector<char> v(arr[i], arr[i]+20);
		board.push_back(v);
	}
	Solution so;
	so.solve(board);
	return 0;
}