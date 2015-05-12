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
		//Ԥ������*******X****X****����Ĵ�תΪ*X*X*����ʽ
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
		//�����x��y��ֵ���ǰ�����ĸ�򣿵��ַ���
		//���һ��y��*
		if (arr.size() == 1){
			if (arr[0] == "*") return true;
			else return fun(s, arr[0]);
		}
		//�������y*x*x*y or y*x* or *x*y���������y
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
				int flag = 0;				//����Ƿ���s��left��ͷ���Ӵ����Ƿ���ƥ����
				while (left<right){
					if (right - left < arr[x].length())  return false;	//�ж��Ƿ�s���㹻���ȵĴ�ȥƥ�䣬û����ֱ�ӷ���false
					if (fun(s.substr(left, arr[x].length()), arr[x])){
						left += arr[x].length();
						flag = 1;
						break;
					}
					else{
						left++;
					}
				}
				if (!flag) return false;	//���û���ҵ��κ�ƥ��λ�ã���ֱ�ӷ���false
			}
			x++;
		}
		if (x == arr.size()) return true;  //ȫ��ƥ����true
		return false;
	}
};
int main()
{
	Solution so; //gxvoym
	cout << so.isMatch("bbbbab", "*a?*b") << endl;
	return 0;
}