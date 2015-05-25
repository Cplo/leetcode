#include<iostream>
#include<vector>
#include<string>
#include<string.h>
using namespace std;

int ways[1000];

class Solution {
public:
	int count(int n) {
		if (n == 0) {
			ways[0] = 0; 
			return 0;
		}
		if (n == 1) {
			if (data[0] <= '9'&&data[0] >= '1') ways[1] = 1;
			else ways[1] = 0;
			return ways[1];
		}
		int a = 0;
		int x = data[n - 1] - '0' + 10 * (data[n - 2] - '0');
		if (x <= 26 && x >= 10) {
			if (ways[n - 2] == -1) ways[n - 2] = count(n - 2);
			a += ways[n - 2];
			if (n == 2) a += 1;
		}
		if (data[n - 1] <= '9'&&data[n - 1] >= '1') {
			ways[n - 1] = count(n - 1);
			a += ways[n - 1];
		}
		ways[n] = a;
		return a;
	}
	int numDecodings(string s) {
		int n = s.length();
		data = s;
		memset(ways, -1, (n + 1)*sizeof(int));
		return count(n);
	}
private:
	string data;
};

int main(void) {
	Solution so;
	cout<<so.numDecodings("000001")<<endl;
	return 0;
}