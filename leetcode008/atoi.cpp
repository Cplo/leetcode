#include<iostream>
using namespace std;
#include<string>
#include<string.h>
#include<float.h>
class Solution {
public:
	int atoi(string str) {
		int i = 0;
		while (i < str.length() && str[i] == ' ')	{ i++; }
		str = str.substr(i);
		if (str.length() <= 0) return 0;
		char arr[13];
		int flag = 0;
		for (i = 0; i < 12 && i < str.length(); i++)
		{
			if (i == 0 && (str[i] == '-' || str[i] == '+') || str[i] >= '0' && str[i] <= '9')	arr[i] = str[i];
			else break;
		}
		arr[i] = '\0';
		int len = strlen(arr);
		if (!len || len == 1 && (arr[0] == '+' || arr[0] == '-')) return 0;
		long long k;
		sscanf(arr, "%lld", &k);
		if (k > INT_MAX) k = INT_MAX;
		if (k < INT_MIN) k = INT_MIN;
		return k;
	}
};
int main()
{
	Solution so;
	cout<<so.atoi("1234567890123456789012345678901234567890")<<endl;
	return 0;
}