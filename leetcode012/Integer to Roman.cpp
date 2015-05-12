#include<iostream>
using namespace std;
#include<string>
class Solution {
public:
	string intToRoman(int num) {
		string ans;
		int atom_int[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
		string atom_str[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
		int i = 0;
		while (num){
			if (num - atom_int[i] >= 0)
			{
				ans += atom_str[i];
				num -= atom_int[i];
			}
			else{
				i++;
			}
		}
		return ans;
	}
};

int main(){
	Solution so;
	cout << so.intToRoman(9) << endl;
	return 0;
}