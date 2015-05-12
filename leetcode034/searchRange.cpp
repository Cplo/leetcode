#include<iostream>
using namespace std;
#include<vector>
class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> ans;
		int left = 0;
		int right = nums.size()-1;
		int mid = (left + right) / 2;
		while (left <= right&&mid>=0&&mid<nums.size()){
			if (nums[mid] > target){
				right = mid;
			}
			else if (nums[mid] < target){
				left = mid;
			}
			else{
				int m = mid;
				int n = mid;
				while (n < nums.size() && m >= 0){
					if (target != nums[n] && target != nums[m])
						break;
					if (target == nums[m]) m--;
					if (target == nums[n]) n++;
				}
				if (m < 0 || target != nums[m]) ans.push_back(m + 1);
				else ans.push_back(m);
				if (n == nums.size() || target != nums[n]) ans.push_back(n - 1);
				else ans.push_back(n);
				break;
			}
			mid = (left + right) / 2;
			if (mid == left){
				if (target > nums[mid]) {
					left++; mid++;
				}
				if (target < nums[mid]) {
					mid--; right--;
				}
			}
		}
		if (ans.empty()){
			ans.push_back(-1);
			ans.push_back(-1);
		}
		return ans;
	}
	int searchInsert(vector<int>& nums, int target) {
		int left = 0;
		int right = nums.size() - 1;
		int mid = (left + right) / 2;
		while (left <= right&&mid >= 0 && mid<nums.size()){
			if (nums[mid] > target){
				right = mid;
			}
			else if (nums[mid] < target){
				left = mid;
			}
			else{
				int m = mid;
				while (m >= 0){
					if (target != nums[m])
						break;
					if (target == nums[m]) m--;
				}
				if (m < 0 || target != nums[m]) return m+1;
				else return m;
			}
			mid = (left + right) / 2;
			if (mid == left){
				if (target > nums[mid]) {
					left++; mid++;
				}
				if (target < nums[mid]) {
					mid--; right--;
				}
			}
		}
		return left;
	}
};
int main(){
	Solution so;
	vector<int> v;
	v.push_back(1);
	v.push_back(3);
	v.push_back(5);/*
	v.push_back(5);*/
	cout<<so.searchInsert(v, 3);
	//for (int i = 0; i < ans.size(); i++){
	//	cout << ans[i] << endl;
	//}
	return 0;
}