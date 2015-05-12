#include<iostream>
using namespace std;
#include<math.h>

class Solution {
public:
	bool isPalindrome(int x) {
		long long k = x;
		if (k < 0) return false;
		int i = 9;
		while (!((int)(x / pow(10, i)) % 10)) i--;
		for (int j = i; j > i / 2; j--){
			if ((int)(x / pow(10, j)) % 10 != (int)(x / pow(10, i - j)) % 10) return false;
		}
		return true;
	}
};
int main()
{
	Solution so;
	cout << so.isPalindrome(11) << endl;
	return 0;
}