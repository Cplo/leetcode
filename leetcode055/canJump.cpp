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
	bool canJump(vector<int>& nums) {
		if (nums.empty()) return true;
		int goal = nums.size();
		if (goal == 1) return true;
		if (nums[0] >= goal - 1) return true;
		int h[100000];
		int head = 0;
		int tail = 0;
		int cur = 0;
		for (int i = 0; i < nums[0]; i++){
			h[tail] = i + 1;
			tail++;
		}
		cur = nums[0];
		while (head < tail){
			if (h[head] + nums[h[head]] >= goal - 1) return true;
			if (h[head] + nums[h[head]] < cur) { head++; continue; }
			for (; cur <= h[head] + nums[h[head]]; cur++){
				h[tail] = cur;
				tail++;
			}
		}
		return false;
	}
};

int main(){
	int a[] = { 1,2 ,0,1,0};
	vector<int> v(a, a + 5);
	Solution so;
	cout << so.canJump(v) << endl;
	return 0;
}