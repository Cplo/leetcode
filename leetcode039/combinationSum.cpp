#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
class Solution {
public:
	void fun2(vector<vector<int> > &ans, vector<int> &num, vector<int> v, int i, int target,int size){
		for (; i < num.size();){
			if (num[i] > target) break;
			if (num[i] == target) {
				int n = v.size() - size;
				int x = 0;
				while (x < n) { v.pop_back(); x++; }
				v.push_back(target); ans.push_back(v); break; 
			}
			int count = 1;
			int can = num[i];
			i++;
			while (i  < num.size() && num[i ] == num[i-1]) { i++; count++; }

			for (int k = 1; k <= count; k++){
				int remain = target - can * k;
				int n = v.size() - size;
				int x = 0;
				while (x < n) { v.pop_back(); x++; }
				for (int t = 0; t < k; t++){
					v.push_back(can);
				}
				if (!remain) { ans.push_back(v); break; }
				if (i  < num.size())
					fun2(ans, num, v, i, remain,v.size());
			}
		}
	}
	vector<vector<int> > combinationSum2(vector<int> &num, int target) {
		sort(num.begin(), num.end());
		vector<vector<int> > ans;
		for (int i = 0; i < num.size(); ){
			if (num[i] > target) break;
			if (num[i] == target) { vector<int> v; v.push_back(target); ans.push_back(v); break; }
			int count = 1;
			int can = num[i];
			i++;
			while (i < num.size() && num[i ] == num[i-1]) { i++; count++; }
			for (int k = 1; k <= count; k++){
				int remain = target - can * k;
				vector<int> v(k,can);
				if (!remain) { ans.push_back(v); break; }
				if (i  < num.size())
					fun2(ans, num, v, i, remain,v.size());
			}
		}
		return ans;
	}
};

int main(){
	Solution so;
	//10, 1, 2, 7, 6, 1, 5
	vector<int> v;
	v.push_back(10);
	v.push_back(1);
	v.push_back(2);
	v.push_back(7);
	v.push_back(6);
	v.push_back(1);
	v.push_back(5);
	vector<vector<int>> ans = so.combinationSum2(v, 10);
	for (auto a : ans){
		for (auto b : a){
			cout << b << ' ';
		}
		cout << endl;
	}
	return 0;
}