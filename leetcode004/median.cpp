#include<iostream>
using namespace std;

class Solution {
public:
	double findMedianSortedArrays(int A[], int m, int B[], int n) {
		double ans=0;
		int len = (m + n + 1) / 2;
		int flag = (m + n) % 2;		//用来标记中位数是一个数还是两个数的均值（1代表一个数，0代表两数均值）
		int finish = 0;				//用来表示寻找工作是否结束
		int count = 0;
		int i=0,j=0;
		while (i < m&&j < n)
		{
			if (A[i] < B[j])
			{ 
				count++; 
				if (count == len) {
					ans += A[i]; if (flag) { finish = 1; break; }
				}
				if (count == len + 1){ 
					ans += A[i]; finish = 1; break;
				}
				i++;
			}
			else { 
				count++; 
				if (count == len) {
					ans += B[j]; if (flag){ finish = 1; break; }
				}
				if (count == len + 1){
					ans += B[j]; finish = 1; break; 
				}
				j++;
			}
		}
		while (!finish&&i < m)
		{
			count++;
			if (count == len) { ans += A[i]; if (flag) break; }
			if (count == len + 1){ ans += A[i]; break; }
			i++;
		}
		while (!finish&&j < n)
		{
			count++;
			if (count == len) { ans += B[j]; if (flag) break; }
			if (count == len + 1){ ans += B[j]; break; }
			j++;
		}
		ans = flag ? ans : ans / 2;
		return ans;
	}
};

int main()
{
	Solution so;
	int A[2] = { 1,2 };
	int B[3] = { 1,2,3};
	cout<<so.findMedianSortedArrays(A,2,B,3);
	return 0;
}