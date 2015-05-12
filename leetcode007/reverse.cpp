#include<iostream>
using namespace std;
#include<string.h>
#include<float.h>
class Solution {
public:
	int reverse(int x) {
		int flag = 0;
		if (x < 0) { flag = 1;}// x = -x; }
		char arr[33];
		char arr1[33];
		long long k;
		sprintf(arr, "%d", x);//格式化输出到arr数组；
		int len = strlen(arr);
		int i=0;
		if (flag) { arr1[0] = '-'; i = 1; }
		if (flag){
			for (; i < len; i++)
				arr1[i] = arr[len - i];
		}
		else{
			for (; i < len; i++)
				arr1[i] = arr[len - i - 1];
		}
		arr1[len] = '\0';
		sscanf(arr1, "%lld", &k);//格式化输入到k中
		//cout << k<<endl<<len << endl;
		if (k < INT_MIN || k > INT_MAX) k = 0;
		return k;
	}
};

int main()
{
	Solution so;
	cout << so.reverse(1000000003) << endl;
	return 0;
}