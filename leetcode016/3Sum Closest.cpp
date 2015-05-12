#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<math.h>

class Solution {
public:
	int threeSumClosest(vector<int> &num, int target) {
		int ans;
		int n = num.size();
		if (n < 3) return ans;
		sort(num.begin(), num.end());
		int i = 0, j = n - 1;
		vector<int> left;
		vector<int> right;
		for (int z = 0; z < num.size(); z++){
			cout << num[z] << ' ';
		}
		cout << endl;
		int flag = 0;
		while (i < n){
			left.push_back(i);
			while (i + 1 < n&&num[i + 1] == num[i]) i++;
			i++;
		}
		while (j >= 0){
			right.push_back(j);
			while (j - 1 >= 0 && num[j - 1] == num[j]) j--;
			j--;
		}
		for (i = 0; i < left.size(); i++){
			for (j = 0; j < right.size(); j++){
				if (right[j] - left[i] <= 1) break;
				int sub = target - num[left[i]] - num[right[j]];
				int k;
				for (k = left[i] + 1; k < right[j]-1; k++){
					if (num[k] >= sub) break;
				}
				if (sub == num[k]) return target;
				int x = num[k] - sub;
				if (k - 1 > left[i] && abs(num[k - 1] - sub) < abs(num[k] - sub)) x = num[k - 1] - sub;
				if (!flag){ flag = 1; ans = target + x; }
				else if (abs(ans - target) > abs(x)) ans = target + x;
			}
		}
		return ans;
	}//-1 2 1 -4
};
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
	cout<< so.threeSumClosest(num,1)<<endl;
	return 0;
}