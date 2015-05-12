#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<map>
#include<string.h>
#include<string>
#include<queue>
#include<float.h>

class Solution {
public:
	bool isNumber(string s) {
		int n = s.length();
		int i=0;
		while (i < n&&s[i] == ' '){
			i++;
		}
		if (s[i] == '+' || s[i] == '-'){
			i++;
		}
		while (n - 1 >= 0 && s[n - 1] == ' '){
			n--;
		}
		if (i >= n) return false;
		int eflag = 0;
		int dflag = 0;
		int fflag = 0;
		while (i < n){
			if (s[i] >= '0'&&s[i] <= '9'){
				i++; continue;
			}
			else if (s[i] == '.'){
				if (eflag||dflag) return false;
				dflag = 1;
				i++;
				continue;
			}
			else if (s[i] == 'e'){
				if (eflag) return false;
				if (i - 1 >= 0 && s[i - 1] == '.'){
					if (!(i - 2 >= 0 && (s[i - 2] >= '0' && s[i-2] <= '9'))) return false;
				}
				if (i - 1 < 0 || s[i - 1] == ' ' || s[i-1] == '+' || s[i-1] == '-') return false;
				eflag = 1;
				i++; continue;
			}
			else if (s[i] == '+' || s[i] == '-'){
				if (!eflag || fflag) return false;
				i++; fflag = 1; continue;
			}
			else{
				return false;
			}
		}
		if (i - 1 >= 0 && (s[i - 1] == 'e'||s[i-1]=='+'||s[i-1]=='-')) return false;
		if (i - 1 >= 0 && s[i - 1] == '.') {
			if (i - 2 >= 0 && (s[i - 2] >= '0'&&s[i] <= '9')) return true;
			else return false;
		}
		return true;
	} 
	vector<int> plusOne(vector<int>& digits) {
		int n = digits.size();
		if (digits[n-1] < 9) {
			digits[n - 1]++; return digits;
		}
		else{
			int i = n - 1;
			while (i >= 0&&digits[i]==9){
				digits[i] = 0;
				i--;
			}
			if (i >= 0) digits[i]++;
			else digits.insert(digits.begin(), 1);
		}
		return digits;
	}
	string addBinary(string a, string b) {
		string ans;
		int i = a.length() - 1;
		int j = b.length() - 1;
		int carry=0;
		int sum;
		char ch;
		while (i >= 0 && j >= 0){
			sum = carry + a[i] + b[j] - 2 * '0';
			if (sum < 2){
				carry = 0;  ch = sum + '0'; ans = ch + ans;
			}
			else {
				carry = 1; ch = sum % 2 + '0'; ans = ch + ans;
			}
			i--; j--;
		}
		while (i >= 0){
			sum = carry + a[i] - '0';
			if (sum < 2){
				carry = 0; ch = sum + '0'; ans = ch + ans;
			}
			else {
				carry = 1; ch = sum % 2 + '0'; ans = ch + ans;
			}
			i--;
		}
		while (j >= 0){
			sum = carry + b[j] - '0';
			if (sum < 2){
				carry = 0; ch = sum + '0'; ans = ch + ans;
			}
			else {
				carry = 1;  ch = sum % 2 + '0'; ans = ch + ans;
			}
			j--;
		}
		if (carry) ans = '1' + ans;
		return ans;
	}
};
/*
1
+1
3.
3.e1
+3.e-1


*/
int main(){
	Solution so;
	vector<int> v;
	v.push_back(0);
	int i = 0;
	//while (i++<101){
	//	so.plusOne(v);
	//	for (auto m : v)
	//		cout << m;
	//	cout << endl;
	//}
	cout << so.addBinary("1010", "1011") << endl;
	return 0;
}