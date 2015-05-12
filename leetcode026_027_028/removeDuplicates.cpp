#include<iostream>
using namespace std;
#include<string>
//运行时间：8ms
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
	cout << so.strStr("aaaaaaaab", "ab")<<endl;
	return 0;
}