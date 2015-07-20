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

class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int N = gas.size();
		for (int i = 0; i < N; ) {
			int start = i;
			int count = 0;
			int sum = 0;
			while (count < N) {
				sum += gas[start % N];
				if (sum < cost[start % N]) break;
				sum -= cost[start % N];
				count++; start++;
			}
			if (count == N) return i;
			i = start + 1;
		}
		return -1;
	}
};
int main(void) {
	int a[] = { 5, 0, 9, 4, 3, 3, 9, 9, 1, 2 }; int b[] = { 6, 7, 5, 9, 5, 8, 7, 1, 10, 5 };
	vector<int> v1(a, a + 10);
	vector<int> v2(b, b + 10);
	Solution so;
	cout << so.canCompleteCircuit(v1, v2) << endl;
	return 0;
};