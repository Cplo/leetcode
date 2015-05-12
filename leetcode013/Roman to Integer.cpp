#include<iostream>
using namespace std;
#include<string>
class Solution {
public:
	int romanToInt(string s) {
		int ans = 0;
		int map[100];
		map['I'] = 1;
		map['V'] = 5;
		map['X'] = 10;
		map['L'] = 50;
		map['C'] = 100;
		map['D'] = 500; 
		map['M'] = 1000;
		int pre = map[s[0]];
		ans += pre;
		for (int i = 1; s[i]; i++){
			if (map[s[i]] <= pre){ ans += map[s[i]]; pre = map[s[i]];  }
			else { ans = ans + map[s[i]] - pre * 2; pre = map[s[i]]; }
		}
		return ans;
	}
};
int main(){
	Solution so;
	cout << so.romanToInt("MMMCMXCIX") << endl;
	return 0;
}