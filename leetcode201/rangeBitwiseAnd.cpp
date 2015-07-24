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
	int rangeBitwiseAnd(int m, int n) {
		string s_n;
		int cp_n = n;
		while (cp_n) {
			char ch = '0'+ (cp_n & 1);
			s_n = ch + s_n;
			cp_n >>= 1;
		}
		int len = s_n.length();
		int num = 0;
		int bit_and = 0;
		for (int i = 0; i < len; i++){
			if (s_n[i] == '0') {
				num *= 2; bit_and *= 2;
			}
			else {
				num = num * 2 + 1;
				int k = num * pow(2, len - 1 - i);
				if (m < k) bit_and *= 2;
				else bit_and = bit_and * 2 + 1;
			}
		}
		return bit_and;
	}
	long long reverseBits(long long n) {
		long long ans = 0;
		int i = 0;
		while (n) {
			ans = ans * 2 + (n & 1);
			n >>= 1;
			i++;
		}
		return ans * pow(2, 32 - i);
	}
};
int main(void){
	Solution so;
	cout << so.rangeBitwiseAnd(5, 5) << endl;
	cout << so.reverseBits(43261596) << endl;
	return 0;
}