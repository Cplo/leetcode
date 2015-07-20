#include<iostream>
#include<vector>
#include<string>
#include<string.h>
#include<algorithm>
#include<map>
#include<float.h>
#include<stack>
#include<math.h>
#include<queue>
#include<unordered_set>
using namespace std;

class Solution {
public:
	string fractionToDecimal(int numerator, int denominator) {
		long long integer = (long long )numerator / denominator;
		long long numerator1 = numerator;
		long long denominator1 = denominator;
		numerator1 = numerator1 % denominator1;
		if (numerator1 < 0)	numerator1 = -numerator1;
		if (denominator1 < 0) denominator1 = -denominator1;
		char ch[10000];
		sprintf(ch, "%lld", denominator1);
		int len_d = strlen(ch);
		map<int,int> m;
		m[numerator1] = -1;
		string decimal;
		while (1) {
			if (!numerator1) {
				//³ý¸É¾»
				if (decimal.empty()) {
					sprintf(ch, "%lld", integer);
					string ans(ch, strlen(ch));
					if (!integer) if (numerator < 0 && denominator>0 || numerator > 0 && denominator < 0) ans = '-' + ans;
					return ans;
				}
				else {
					sprintf(ch, "%lld.%s", integer, decimal.c_str());
					string ans(ch, strlen(ch));
					if (!integer) if (numerator < 0 && denominator>0 || numerator > 0 && denominator < 0) ans = '-' + ans;
					return ans;
				}
			}
			sprintf(ch, "%lld", numerator1);
			int len_n = strlen(ch);
			for (int i = 0; i < len_d - len_n; i++) {
				numerator1 *= 10;
				if (numerator1 < denominator1) {
					decimal += '0'; m[numerator1] = decimal.size() - 1;
				}
			}
			if (numerator1 < denominator1) numerator1 *= 10;
			int x = numerator1 / denominator1;
			numerator1 = numerator1 % denominator1;
			if (m.find(numerator1) != m.end()) {
				//Ñ­»·½áÊø
				char y = x + '0';
				decimal += y;
				int idx = m[numerator1];
				sprintf(ch, "%lld.%s(%s)", integer, decimal.substr(0, idx+1).c_str(), decimal.substr(idx+1).c_str());
				string ans(ch, strlen(ch));
				if (!integer) if (numerator < 0 && denominator>0 || numerator > 0 && denominator < 0) ans = '-' + ans;
				return ans;
			}
			char y = x + '0';
			decimal += y;
			m[numerator1] = decimal.size() - 1;
		}
	}
};

int main(void) {
	Solution so;//2,3    1/90 
	cout << so.fractionToDecimal(-1, -2147483648) << endl;
	return 0;
}