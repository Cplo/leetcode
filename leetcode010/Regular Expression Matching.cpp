#include<iostream>
using namespace std;
#include<string.h>
#include<vector>
/*
	'.' Matches any single character.	任意1个字符
	'*' Matches zero or more of the preceding element.	0到多个字符

	The matching should cover the entire input string (not partial).

	The function prototype should be:
	bool isMatch(const char *s, const char *p)

	Some examples:
	isMatch("aa","a") → false
	isMatch("aa","aa") → true
	isMatch("aaa","aa") → false
	isMatch("aa", "a*") → true
	isMatch("aa", ".*") → true
	isMatch("ab", ".*") → true
	isMatch("aab", "c*a*b") → true
	*/
//class Solution {
//public:
//	//理解为*为通配符了
//	/*bool isMatch(const char *s, const char *p) {
//		int slen = strlen(s);
//		int plen = strlen(p);
//		int i = 0,j = 0;
//		int flag = 0;
//		while (j < plen && i < slen)
//		{
//			switch (p[j])
//			{
//				case '.': {
//					i++; j++; break;
//				};
//				case '*':{
//					flag = 1; j++; break;
//				}
//				default:{
//					while (flag&&i < slen&&s[i] != p[j]) i++;
//					if (flag&&i == slen) return false;
//					else if(s[i] == p[j]) { flag = 0; j++; i++; }
//					else return false;
//					break;
//				}
//			}
//		}
//		while (j<plen)
//		{
//			if (p[j] != '*')	return false;
//			else j++;
//		}
//		if (i != slen&&j == plen&&!flag) return false;
//		if (i != slen&&j == plen&&flag) return true;
//		if (i == slen&&j == plen) return true;
//	}*/
//	bool isMatch(const char *s, const char *p) {
//		int slen = strlen(s);
//		int plen = strlen(p);
//		string *arr = new string[plen];
//		int alen = 0;
//		int i = 0,j;
//		int flag = 0;//标记.*    
//		while(i<plen){
//			if (i + 1 < plen&&p[i + 1] == '*'){
//				arr[alen] += p[i];
//				arr[alen] += p[i + 1];
//				i = i + 2;
//			}
//			else{
//				arr[alen] += p[i];
//				i++; 
//			}
//			alen++;
//		}
//		i = j = 0;
//		while (i < slen&&j < alen){
//			if (arr[alen - 1].length() == 1){
//				if (arr[alen - 1][0] == s[slen - 1] || arr[alen - 1][0] == '.') { alen--; slen--; }
//				else return false;
//			}
//			else if (arr[j].length() == 1){
//				if (arr[j][0] == s[i] || arr[j][0] == '.') { i++; j++; }
//				else return  false;
//			}
//			else if (arr[alen - 1].length() == 2 && arr[alen - 1][0] != '.')/*后往前遇到A* */{
//				if (arr[alen - 1][0] != s[slen-1]) alen--;
//				else{
//					char goal = s[slen-1];
//					int counts = 0, counta = 0;
//					while (i < slen&&s[slen - 1] == goal){
//						counts++; slen--;
//					}
//					while (j < alen&&arr[alen - 1][0] == goal){
//						if (arr[alen - 1].length() == 1)
//							counta++;
//						alen--;
//					}
//					if (counta > counts) return false;
//				}
//			}
//			else if (arr[j].length() == 2 && arr[j][0] != '.')/*前往后遇到A* */ {
//				if (arr[j][0] != s[i]) j++;
//				else{
//					char goal = s[i];
//					int counts = 0, counta = 0;
//					while (i < slen&&s[i] == goal) {
//						counts++; i++;
//					}
//					//a a*
//					//a a  待定
//					//a a*
//					while (j < alen&&arr[j][0] == goal){
//						if (arr[j].length()==1)
//							counta++;
//						j++;
//					}
//					if (counta > counts) return false;
//				}
//			}
//			else if (arr[j].length() == 2 && arr[j][0] == '.')/* 前往后遇到.* */{
//				/* .*xoy.* */
//				if (alen - 1 - j <= 1) return true;
//				else {
//					vector<string> substr;
//					int k = j + 1;
//					while (k<alen)
//					{
//						if (k < alen && (arr[k].length() == 1 || arr[k].length() == 2 && arr[k][0] != '.'))
//						{
//							substr.push_back(arr[k]);
//							k++;
//						}
//						else break;
//					}
//					j = j + substr.size() + 1;
//					int isHave = 0;
//					k = i;
//					for (; k < slen; k++){
//						int u = k;
//						int m;
//						for (m = 0; u<slen&&m < substr.size();){
//							if (substr[m].length() == 1 && (substr[m][0] == s[u] || substr[m][0] == '.'))//未完待续！！！！！！！！！！！！！！！！！！！
//							{
//								m++; u++;
//							}
//							else{
//								char goal = s[u];
//								int counts1 = 0, counts2=0;
//								while (m < substr.size() && substr[m][0] == goal){
//									if (substr[m].length() == 1)
//										counts1++;
//									m++;
//								}
//								while (u < slen&&s[u] == goal){
//									counts2++;
//									u++;
//								}
//								if (counts1 > counts2) return false;
//							}
//						}
//						if (m == substr.size()) {
//							isHave = 1;
//							i = u;
//							break;
//						}
//					}
//					if (!isHave) return false;
//				}
//			}
//			else return false;
//		}
//		if(i==slen&&j==alen)	return true;
//		if(j<alen) {
//			for (int k = j; k < alen; k++)
//				if (arr[k].length() == 1) return false;
//			return true;
//		}
//		return false;
//		//for ();
//	}
//};
class Solution {
public:
	bool isMatch(const char *s, const char *p) {
		int slen = strlen(s);
		int plen = strlen(p);
		int alen = 0;
		int i = 0, j = 0; 
		int count_p_single = 0;

		string *arr = new string[plen];		
		//预处理正则表达式
		while (i < plen){
			if (i + 1 < plen&&p[i + 1] == '*'){
				arr[alen] += p[i];
				arr[alen] += p[i + 1];
				i = i + 2;
			}
			else{
				arr[alen] += p[i];
				i++;
				count_p_single++;
			}
			alen++;
		}

		//vector<int> vec_i;		//i在字符串s上的所有当前候选位置
		//vector<int> vec_j;		//j在字符串arr上的所有当前候选位置
		i = j = 0;
		//vec_i.push_back(i);
		//vec_j.push_back(j);
		int queue_i[100000];		//i在字符串s上的所有当前候选位置	
		int queue_j[100000];		//j在字符串arr上的所有当前候选位置
		int tail_i;					//队尾，进队操作
		int head_i;					//对头，出队操作
		int tail_j;
		int head_j;
		tail_i = tail_j = head_i = head_j = 0;
		queue_i[tail_i++ % 100000] = 0;
		queue_j[tail_j++ % 100000] = 0;
		//while (vec_i.size() > 0){
		while (head_i  % 100000 != tail_i % 100000){
			//i = vec_i.back();
			//j = vec_j.back();
			//vec_i.pop_back();
			//vec_j.pop_back();
			i = queue_i[head_i++ % 100000];
			j = queue_j[head_j++ % 100000];
			
			if (i == slen && j == alen) return true;
			if (i == slen && j<alen) {
				int flag = 0;
				for (int k = j; k < alen; k++)
					if (arr[k].length() == 1) flag = 1;
				if (!flag)
					return true;
			}
			if (i >= slen || j >= alen || slen-i < count_p_single) continue;
			//情况1： a 或 .
			if (arr[j].length() == 1){
				if (arr[j][0] == s[i] || arr[j][0] == '.'){
					i++; j++;
					//vec_i.push_back(i);
					//vec_j.push_back(j);
					queue_i[tail_i++ % 100000] = i;
					queue_j[tail_j++ % 100000] = j;
					count_p_single--;
				}
				else
				{
					continue;
				}
			}
			//情况2：a*    
			else if (arr[j].length() == 2 && arr[j][0] != '.'){
				//vec_i.push_back(i);
				//vec_j.push_back(j + 1);
				queue_i[tail_i++ % 100000] = i;
				queue_j[tail_j++ % 100000] = j + 1;
				if(arr[j][0]==s[i]){
					char goal = s[i];
					int counts = 0, counta = 0;
					while (i < slen&&s[i] == goal) {
						counts++; 
						i++;
					}
					
					while (j < alen&&arr[j][0] == goal){
						if (arr[j].length() == 1)
							counta++;
						j++;
					}
					//aaa		3
					//a*aa*		1      3>=1
					if (counta > counts) continue;
					for (int x = counta; x <= counts; x++){
						//vec_i.push_back(i-counts+x);
						//vec_j.push_back(j);
						queue_i[tail_i++ % 100000] = i - counts + x;
						queue_j[tail_j++ % 100000] = j;
					}
				}
			}
			//情况3：.*
			else if (arr[j].length() == 2 && arr[j][0] == '.'){
				if (alen - 1 - j <= 0) return true;
				j = j + 1;
				for (int m = i; m <= slen; m++){
					//vec_i.push_back(m);
					//vec_j.push_back(j);
					queue_i[tail_i++ % 100000] = m;
					queue_j[tail_j++ % 100000] = j;
				}
			}
		}
		return false;
	}
};
int main()
{
	Solution so; //gxvoym
	cout << so.isMatch("abaabababbcbcabbcbc", "b*ab.*.*.*.b..*") << endl;
	return 0;
}