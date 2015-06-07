#include<iostream>
#include<vector>
using namespace std;
#include<string>
//����ʱ�䣺8ms
class Solution {
public:
	int removeDuplicates(int A[], int n) {
		if (!n) return 0;
		int pre = A[0];
		int j = 1;
		for (int i = 1; i < n; ){
			if (pre != A[i]) {
				A[j++] = A[i]; pre = A[i];
				i++;
			}
			else i++;
		}
		return j;
	}
	int removeDuplicates(vector<int>& nums) {
		int n = nums.size();
		int ans = 0;
		int k;
		int count;
		int j = 0;
		for (int i = 0; i < n;) {
			k = i;
			count = 1;
			while (k+1 < n&&nums[k+1] == nums[k]){
				k++;
				count++;
			}
			if (count >= 2) {
				ans += 2;
				nums[j] = nums[j + 1] = nums[i];
				j += 2;
			}
			else {
				ans += 1;
				nums[j++] = nums[i];
			}
			i = k+1;
		}
		return ans;
	}
	int removeElement(int A[], int n, int elem) {
		if (!n) return 0;
		int j = 0;
		for (int i = 0; i < n;){
			if (elem != A[i]) {
				A[j++] = A[i];
				i++;
			}
			else i++;
		}
		return j;
	}
	int strStr(string haystack, string needle) {
		if (needle.empty()) return 0;
		int h_len = haystack.length();
		int n_len = needle.length();
		if (h_len < n_len) return -1;
		//int ans = haystack.find(needle, 0);
		//if (ans == string::npos) return -1;
		//return ans;
		int i = 0;
		int m = 0;
		int j = 0;
		bool flag = false;
		int ans;
		while (i < h_len){
			ans = i - m;
			j = m;
			m = 0;
			while (i < h_len&&j < n_len&&haystack[i] == needle[j]){
				if (j){
					if (needle[j] == needle[m])
						m++;
					else m = 0;
				}
				i++; j++;
			}
			if (j == n_len) { flag = true; break; }
			if (!j) i++;
		}
		if (flag) return ans;
		return -1;
	}
};
int main(){
	Solution so;
	/*int A[] = { 1, 2, 3, 3, 3, 4, 4, 4, 5 ,5};
	int n = so.removeElement(A, 10,2);
	for (int i = 0; i < n; i++)
		cout << A[i] << endl;*/
	//cout << so.strStr("aaaaaaaab", "ab")<<endl;
	int a[] = { 1, 1, 1, 2, 2, 3 };
	vector<int> v(a, a + 6);
	cout << so.removeDuplicates(v) << endl;
	return 0;
}