#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<map>
#include<string.h>
#include<string>
#include<queue>
class Solution {
public:
	int jump(vector<int>& nums) {
		int goal = nums.size();
		if (goal == 1) return 0;
		if (nums[0] >= goal - 1) return 1;
		int h[100000];
		int l[100000];
		int head = 0;
		int tail = 0;
		int cur=0;
		for (int i = 0; i < nums[0]; i++){
			h[tail] = i + 1;
			l[tail] = 1;
			tail++;
		}
		cur = nums[0];
		while (head < tail){
			if (h[head] + nums[h[head]] >= goal - 1) return l[head] + 1;
			if (h[head] + nums[h[head]] < cur) { head++; continue; }
			for (; cur <= h[head] + nums[h[head]]; cur++){
				h[tail] = cur;
				l[tail] = l[head]+1;
				tail++;
			}
		}
	}
};

int main(){
	int a[] = { 0};
	vector<int> v(a,a+1);
	Solution so;
	cout << so.jump(v);
	return 0;
}