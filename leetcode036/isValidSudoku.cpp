#include<iostream>
using namespace std;
#include<vector>
#include<string.h>
#include<map>

//Runtime: 17 ms
class Solution {
public:
	bool fun(vector<vector<char> > &board, int i, int j, int size) {
		for (; i < board.size(); i++){
			if (j == board[i].size()) j = 0;
			for (; j < board[i].size(); j++){
				if (board[i][j] == '.'){
					int a[10];
					int b[10];
					int c[10];
					//初始化
					memset(a, 0, sizeof(int) * 10);
					memset(b, 0, sizeof(int) * 10);
					memset(c, 0, sizeof(int) * 10);
					for (int m = 0; m < board[i].size(); m++){
						int k = board[i][m] - '0';
						if (k <= 9 && k >= 1){
							a[k] = 1;
						}
					}
					for (int m = 0; m < board.size(); m++){
						int k = board[m][j] - '0';
						if (k <= 9 && k >= 1){
							b[k] = 1;
						}
					}
					int s = i / 3 * 3;
					int t = j / 3 * 3;
					for (int m = 0; m < 9; m++){
						int k = board[s + m / 3][t + m % 3] - '0';
						if (k <= 9 && k >= 1){
							c[k] = 1;
						}
					}
					for (int k = 1; k <= 9; k++){
						if (!a[k] && (!b[k]) && (!c[k])){
							board[i][j] = k + '0';
							if (j + 1 == board[i].size() && fun(board, i + 1, 0, size)){
								return true;
							}
							else if (fun(board, i, j + 1, size)){
								return true;
							}
							board[i][j] = '.';
						}
					}
					return false;
				}
			}
		}
		return true;
	}
	void solveSudoku(vector<vector<char> > &board) {
		int a[9][10];				//处理行
		int b[9][10];				//处理列
		int c[9][10];				//处理单元
		//初始化
		for (int i = 0; i < 9; i++){
			memset(a + i, 0, sizeof(int) * 10);
			memset(b + i, 0, sizeof(int) * 10);
			memset(c + i, 0, sizeof(int) * 10);
		}
		int m, n;
		int size = 0;
		for (int i = 0; i < board.size(); i++){
			for (int j = 0; j < board[i].size(); j++){
				int k = board[i][j] - '0';
				if (k <= 9 && k >= 1){
					size++;
					a[i][k] = 1;
					b[j][k] = 1;
					m = i / 3 * 3 + j / 3;
					c[m][k] = 1;
				}
			}
		}
		int x = 0;
		map<int, vector<int> > ma;
		map<int, vector<int>> mb[9];
		map<int, vector<int>> mc[9];
		int pre;
		do{
			pre = size;
			for (int i = 0; i < board.size(); i++){
				for (int j = 0; j < board[i].size(); j++){
					if (board[i][j] == '.'){
						int count = 0;
						m = i / 3 * 3 + j / 3;
						for (int k = 1; k <= 9; k++){
							if (!a[i][k] && (!b[j][k]) && (!c[m][k])){
								ma[k].push_back(j);
								mb[j][k].push_back(i * 9 + j);
								mc[m][k].push_back(i * 9 + j);
							}
						}
					}
				}
				map<int, vector<int> >::iterator it;
				for (it = ma.begin(); it != ma.end(); it++){
					if (it->second.size() == 1 && board[i][it->second.front()] == '.'){
						size++;
						board[i][it->second.front()] = '0' + it->first;
						a[i][it->first] = 1;
						b[it->second.front()][it->first] = 1;
						m = i / 3 * 3 + it->second.front() / 3;
						c[m][it->first] = 1;
					}
				}
				ma.clear();
			}
			for (int i = 0; i < 9; i++){
				for (auto it : mb[i]){
					int x = it.second.front() / 9;
					int y = it.second.front() % 9;
					if (it.second.size() == 1 && board[x][y] == '.'){
						size++;
						board[x][y] = '0' + it.first;
						a[x][it.first] = 1;
						b[y][it.first] = 1;
						m = x / 3 * 3 + y / 3;
						c[m][it.first] = 1;
					}
				}
				mb[i].clear();
				for (auto it : mc[i]){
					int x = it.second.front() / 9;
					int y = it.second.front() % 9;
					if (it.second.size() == 1 && board[x][y] == '.'){
						size++;
						board[x][y] = '0' + it.first;
						a[x][it.first] = 1;
						b[y][it.first] = 1;
						m = x / 3 * 3 + y / 3;
						c[m][it.first] = 1;
					}
				}
				mc[i].clear();
			}
			//cout << size << endl;
			//x++; 
		} while (pre < size && size < 81);
		if (size == 81) return;
		fun(board, 0, 0, size);
	}
};

int main(){
	char a[9][10] = { "..9748...", "7........", ".2.1.9...", "..7...24.", ".64.1.59.", ".98...3..", "...8.3.2.", "........6", "...2759.." };
	vector<vector<char>> v;
	for (int i = 0; i < 9; i++){
		vector<char> c(a[i], a[i] + 9);
		v.push_back(c);
	}
	Solution so;
	so.solveSudoku(v);
	for (auto m : v){
		for (auto n : m){
			cout << n;
		}
		cout << endl;
	}
	return 0;
}