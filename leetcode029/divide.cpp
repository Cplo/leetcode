#include<iostream>
#include<float.h>
#include<string.h>
using namespace std;
class Solution {
public:
	int divide(int dividend, int divisor) {
		if (dividend == INT_MIN && divisor == -1) return INT_MAX;
		//if (dividend == INT_MIN && divisor == 1) return INT_MIN;
		if (!dividend) return 0;
		if (dividend == divisor) return 1;
		if (divisor == 1) return dividend;
		if (divisor == INT_MIN) return 0;
		int ispos = 1;
		long long a = dividend;
		long long b = divisor;
		if (a < 0) { ispos = !ispos;  }
		if (b < 0) { ispos = !ispos; b = -b; }
		int ans=0;
		char dend[11];
		long long p = 0;
		sprintf(dend, "%d", a);
		int d_len = strlen(dend);
		int i = 0;
		if (a < 0) i = 1;
		while (i < d_len){
			p = p*10 + (dend[i] - '0');
			while (p >= b) { p -= b; ans++; }
			i++;
			if (i == d_len) break;
			ans *= 10;
		}
		if (!ispos) ans = -ans;
		return ans;
	}
};
int main(){
	Solution so;
	cout << so.divide(-2147483648, -1017100424) << endl;
}