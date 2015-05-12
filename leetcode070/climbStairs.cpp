#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<map>
#include<string.h>
#include<string>
#include<queue>
#include<float.h>
class Solution {
public:
	int find(int &n, int add, int cur){
		if (cur + add > n) return 0;
		if (cur + add == n) return 1;
		cur += add;
		return find(n, 1, cur) + find(n, 2, cur);
	}
	int climbStairs(int n) {
		if (n == 1)return 1;
		if (n == 2) return 2;
		int *a = new int[n];
		a[0] = 1;
		a[1] = 2;
		for (int i = 2; i < n; i++)
		{
			a[i] = a[i - 1] + a[i - 2];
		}
		return a[n - 1];
	}
};


int main(){
	Solution so;
	cout << so.climbStairs(44) << endl;
	return 0;
}