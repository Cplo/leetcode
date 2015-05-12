#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<map>
#include<string.h>
#include<string>
#include<queue>

struct record
{
	int l;
	int r;
	int cons;
}rec[4];
class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> ans;
		if (matrix.empty()) return ans;
		int m = matrix.size();
		int n = matrix[0].size();
		rec[0].l = 0;
		rec[0].r = n - 1;
		rec[0].cons = 0;

		rec[1].l = 1;
		rec[1].r = m - 1;
		rec[1].cons = n - 1;

		rec[2].l = n - 2;
		rec[2].r = 0;
		rec[2].cons = m - 1;

		rec[3].l = m - 2;
		rec[3].r = 1;
		rec[3].cons = 0;

		int direc = 0;
		int count = 0;
		int sum = n*m;
		while (1){
			if (direc == 0){
				for (int i = rec[direc].l; i <= rec[direc].r; i++){
					ans.push_back(matrix[rec[direc].cons][i]);
				}
				count += (rec[direc].r - rec[direc].l + 1);
				rec[direc].l += 1;
				rec[direc].r -= 1;
				rec[direc].cons += 1;
			}
			else if (direc == 1){
				for (int i = rec[direc].l; i <= rec[direc].r; i++){
					ans.push_back(matrix[i][rec[direc].cons]);
				}
				count += (rec[direc].r - rec[direc].l + 1);
				rec[direc].l += 1;
				rec[direc].r -= 1;
				rec[direc].cons -= 1;
			}
			else if (direc == 2){
				for (int i = rec[direc].l; i >= rec[direc].r; i--){
					ans.push_back(matrix[rec[direc].cons][i]);
				}
				count += (rec[direc].l - rec[direc].r + 1);
				rec[direc].l -= 1;
				rec[direc].r += 1;
				rec[direc].cons -= 1;
			}
			else{
				for (int i = rec[direc].l; i >= rec[direc].r; i--){
					ans.push_back(matrix[i][rec[direc].cons]);
				}
				count += (rec[direc].l - rec[direc].r + 1);
				rec[direc].l -= 1;
				rec[direc].r += 1;
				rec[direc].cons += 1;
			}
			if (sum == count) return ans;
			direc = (direc + 1) % 4;
		}
	}
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> matrix;
		if (n <= 0) return matrix;
		for (int i = 0; i < n; i++){
			vector<int> v(n, 0);
			matrix.push_back(v);
		}
		rec[0].l = 0;
		rec[0].r = n - 1;
		rec[0].cons = 0;

		rec[1].l = 1;
		rec[1].r = n - 1;
		rec[1].cons = n - 1;

		rec[2].l = n - 2;
		rec[2].r = 0;
		rec[2].cons = n - 1;

		rec[3].l = n - 2;
		rec[3].r = 1;
		rec[3].cons = 0;

		int direc = 0;
		int count = 0;
		int sum = n*n;
		while (1){
			if (direc == 0){
				for (int i = rec[direc].l; i <= rec[direc].r; i++){
					count++;
					matrix[rec[direc].cons][i]= count;
				}
				rec[direc].l += 1;
				rec[direc].r -= 1;
				rec[direc].cons += 1;
			}
			else if (direc == 1){
				for (int i = rec[direc].l; i <= rec[direc].r; i++){
					count++;
					matrix[i][rec[direc].cons] = count;
				}
				rec[direc].l += 1;
				rec[direc].r -= 1;
				rec[direc].cons -= 1;
			}
			else if (direc == 2){
				for (int i = rec[direc].l; i >= rec[direc].r; i--){
					count++;
					matrix[rec[direc].cons][i] = count;
				}
				rec[direc].l -= 1;
				rec[direc].r += 1;
				rec[direc].cons -= 1;
			}
			else{
				for (int i = rec[direc].l; i >= rec[direc].r; i--){
					count++;
					matrix[i][rec[direc].cons] = count;
				}
				rec[direc].l -= 1;
				rec[direc].r += 1;
				rec[direc].cons += 1;
			}
			if (sum == count) return matrix;
			direc = (direc + 1) % 4;
		}

	}
};

int main(void){
	int a[3][5] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};

	vector<vector<int>> v;
	for (int j = 0; j < 3; j++){
		vector<int> v1(a[j],a[j]+5);
		v.push_back(v1);
	}

	vector<int> ans;
	Solution so;
	ans = so.spiralOrder(v);
	///*for (auto i : ans){
	//	cout << i << ' ';
	//}*/
	vector<vector<int>> ans1 = so.generateMatrix(10);
	for (auto i : ans1){
		for (auto j : i){
			cout << j << " ";
		}
		cout << endl;
	}
	//cout << endl;
	return 0;
}