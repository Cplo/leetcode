#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<map>
#include<string.h>
#include<string>
//Runtime: 41 ms
class Solution {
public:
	bool fun(string s, string p){
		if (s.length() != p.length()) return false;
		for (int i = 0; i < s.length(); i++){
			if (s[i] == p[i] || p[i] == '?')
				continue;
			else return false;
		}
		return true;
	}
	bool isMatch(string s, string p) {
		int slen = s.length();
		int plen = p.length();
		vector<string> arr;
		if (!plen&&!slen) return true;
		if (!plen) return false;
		int single_count = 0;
		//预处理，将*******X****X****此类的串转为*X*X*的形式
		for (int i = 0; i < plen; ){
			if (p[i] == '*'){
				string v = "*";
				arr.push_back(v);
				i++;
				while (i < plen&&p[i] == '*') i++;
			}
			else{
				string v;
				v += p[i];
				i++;
				single_count++;
				while (i < plen&&p[i] != '*') {
					v+=p[i]; i++;
					single_count++;
				}
				arr.push_back(v);
			}
		}
		if (slen < single_count) return false;
		//这里的x，y均值的是包含字母或？的字符串
		//情况一：y或*
		if (arr.size() == 1){
			if (arr[0] == "*") return true;
			else return fun(s, arr[0]);
		}
		//情况二：y*x*x*y or y*x* or *x*y三种情况的y
		int left=0;
		int right = slen ;
		if (arr[0] != "*"){
			int size = arr[0].size();
			if (size > slen) return false;
			if(fun(s.substr(0, arr[0].size()), arr[0]) == false) return false;
			left = size;
		}
		if (arr.back() != "*"){
			int size = arr.back().size();
			if (size > slen) return false;
			if(fun(s.substr(slen - arr.back().length()), arr.back()) == false) return false;
			right = slen - size;
			arr.pop_back();
		}
		int x = 1;
		while (x < arr.size()){
			if (arr[x] != "*"){
				int flag = 0;				//标记是否在s以left开头的子串中是否有匹配项
				while (left<right){
					if (right - left < arr[x].length())  return false;	//判断是否s有足够长度的串去匹配，没有则直接返回false
					if (fun(s.substr(left, arr[x].length()), arr[x])){
						left += arr[x].length();
						flag = 1;
						break;
					}
					else{
						left++;
					}
				}
				if (!flag) return false;	//如果没有找到任何匹配位置，则直接返回false
			}
			x++;
		}
		if (x == arr.size()) return true;  //全部匹配则true
		return false;
	}
};
int main()
{
	Solution so; //gxvoym
	cout << so.isMatch("bbbbab", "*a?*b") << endl;
	return 0;
}