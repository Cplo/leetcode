#include<iostream>
using namespace std;
#include<vector>

class Solution {
public:
	int search(vector<int>& nums, int target) {
		int mid;
		int length = nums.size();
		if (!length) return -1;
		if (nums[0] == target) return 0;
		if (nums[0] > target){
			for (int i = length-1; i>0; i--){
				if (nums[i] == target) return i;
				if (i - 1 >= 0 && nums[i - 1] > nums[i]) break;
			}
		}
		else{
			for (int i = 0; i < length; i++){
				if (nums[i] == target) return i;
				if (i + 1 < length && nums[i + 1] < nums[i]) break;
			}
		}
		return -1;
		//
		//int left = 0;
		//int right = length - 1;
		//mid = (left + right) / 2;
		
	}
};
int main(){
	return 0;
}