#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<map>
#include<string.h>
#include<string>


class Solution {
public:
	string multiply(string num1, string num2) {
		string ans;
		int n1 = num1.size();
		int n2 = num2.size();
		int carry;
		char ch;
		for (int i = 0; i < n1; i++){
			if (!num1[n1 - 1 - i]) continue;
			string s;
			carry = 0;
			for (int j = n2 - 1; j >=0; j--){
				int k = carry + (num1[n1 - 1 - i] - '0') * (num2[j]-'0');
				carry = k / 10;
				ch = k % 10 + '0';
				s = ch + s;
			}

			if (carry) {
				ch = carry + '0';
				s = ch + s;
			}
			if (ans.empty()) ans = s;
			else {
				carry = 0;
				int m = ans.length(), n = s.length()-1;
				string num ;
				if (m < i){
					string temp(i - m, '0');
					num = s + temp + ans;
				}
				else if(m == i){
					num = s + ans;
				}
				else{
					num = ans.substr(m - i);
					m = m - i - 1;
					while (m >= 0 && n >= 0){
						int k = carry + ans[m] + s[n] - 2 * '0';
						carry = k / 10;
						ch = k % 10 + '0';
						num = ch + num;
						m--; n--;
					}
					while (m >= 0){
						int k = carry + ans[m] - '0';
						carry = k / 10;
						ch = k % 10 + '0';
						num = ch + num;
						m--; 
					}
					while (n >= 0){
						int k = carry + s[n] - '0';
						carry = k / 10;
						ch = k % 10 + '0';
						num = ch + num;
						n--;
					}
					if (carry) {
						ch = carry + '0';
						num = ch + num;
					}
				}
				ans = num;
			}
		}
		while (!ans.empty() && ans[0] == '0'){
			ans = ans.substr(1);
		}
		if (ans.empty()) ans = "0";
		return ans;
	}
};
//5985943922352
//5885843922352
int main(){
	Solution so;
	cout << so.multiply("840477629533", "498828660196") << endl;		
	return 0;
}