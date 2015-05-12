#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
class Solution {
public:
	void nextPermutation(vector<int> &num) {
		//if (false == next_permutation(num.begin(), num.end()))
		//{
		//	int size = num.size();
		//	for (int i = 0; i < size / 2; i++){
		//		num[i] += num[size - 1 - i];
		//		num[size - 1 - i] = num[i] - num[size - 1 - i];
		//		num[i] = num[i] - num[size - 1 - i];
		//	}
		//}
		int size = num.size();
		if (size <= 1) return;
		int i;
		
		for (i = size - 1; i >= 0; i--){
			if (i - 1 >= 0 && num[i - 1] >= num[i]) continue;
			else break;
		}
		
		if (i - 1 >= 0) {
			int idx = i ;
			while (idx + 1<size&&num[idx + 1] > num[i - 1]){
				idx++;
			}
			num[idx] += num[i-1];
			num[i-1] = num[idx] - num[i-1];
			num[idx] = num[idx] - num[i-1];
		}
		int m = i;
		int n = size - 1;
		while (m < n){
			num[m] += num[n];
			num[n] = num[m] - num[n];
			num[m] = num[m] - num[n];
			m++;
			n--;
		}

		//next_permutation(num.begin(), num.end());
	}
};

int main(){
	vector<int> ans;
	ans.push_back(1);
	ans.push_back(1);
	ans.push_back(1);
	//ans.push_back(4);
	//ans.push_back(5);
	Solution so;
	int i = 0;
	while (i<100){
		so.nextPermutation(ans);
		for (auto a : ans){
			cout << a << ' ';
		}
		cout << endl;
		i++;
	}
	return 0;
}