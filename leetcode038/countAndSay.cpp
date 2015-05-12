#include<iostream>
using namespace std;
#include<string>

class Solution {
public:
	string countAndSay(int n) {
		if (n == 1) return "1";
		string ans;
		string init = "1";
		for (int i = 2; i <= n; i++){
			for (int j = 0; j < init.length(); j++){
				int count = 1;
				char ch = init[j];
				while (j + 1 < init.length() && init[j + 1] == init[j]) { j++; count++; }
				ans += (count+'0');
				ans += ch;
			}
			init = ans;
			ans.clear();
		}
		return init;
	}
};

int main(){
	Solution so;
	for (int i = 0; i < 25; i++){
		cout << so.countAndSay(i + 1) << endl;
	}
	return 0;
}