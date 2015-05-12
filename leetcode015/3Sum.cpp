#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
class Solution {
public:
	vector<vector<int>> threeSum(vector<int> &num) {
		vector<vector<int>> ans;
		int n = num.size();
		if (n < 3) return ans;
		sort(num.begin(), num.end());
		for (int z = 0; z < num.size(); z++){
			cout << num[z] << ' ';
		}
		cout << endl;
		int i = 0, j = n - 1;
		int x, y;
		x = y = -1;
		vector<int> neg;
		vector<int> pos;
		while (i < n&&num[i] <= 0){
			if (num[i] < 0) {
				neg.push_back(i);
				while (i + 1 < n&&num[i + 1] == num[i]) i++;
			}
			else{
				x = i;
				break;
			}
			i++;
		}
		while (j >= 0 && num[j] >= 0){
			if (num[j] > 0) {
				pos.push_back(j);
				while (j-1 >= 0&&num[j-1] == num[j]) j--;
			}
			else{
				y = j;
				break;
			}
			j--;
		}
		if (y - x > 1){
			vector<int> v;
			for (int k = 0; k < 3;k++)
				v.push_back(0);
			ans.push_back(v);
		}
		for (i = 0; i < neg.size(); i++){
			for (j = 0; j < pos.size(); j++){
				int add = num[neg[i]] + num[pos[j]];
				int k;
				if (add >= 0){
					for (k = neg[i] + 1; k < pos[j]; k++){
						if (add + num[k] >= 0) break;						
					}
				}
				else{
					for (k = pos[j] - 1; k > neg[i]; k--){
						if (add + num[k] <= 0) break;
					}
				}
				if (add + num[k] == 0){
					vector<int> v;
					v.push_back(num[neg[i]]);
					v.push_back(num[k]);
					v.push_back(num[pos[j]]);
					ans.push_back(v);
				}
			}
		}
		return ans;
	}
};//1 -1 -1 0

int main(){
	int n;
	cin >> n;
	vector<int> num;
	for (int i = 0; i < n; i++){
		int k;
		cin >> k;
		num.push_back(k);
	}
	Solution so;
	vector<vector<int> > ans = so.threeSum(num);
	for (int i = 0; i < ans.size(); i++){
		for (int j = 0; j < ans[i].size(); j++)
			cout << ans[i][j] << ' '; 
		cout << endl;
	}
	return 0;
}//-13 11 11 0 -5 -14 12 -11 -11 -14 -3 0 -3 12 -1 -9 -5 -13 9 -7 -2 9 -1 4