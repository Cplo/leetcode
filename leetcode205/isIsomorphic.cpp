#include<iostream>
#include<vector>
#include<string>
#include<string.h>
#include<algorithm>
#include<map>
#include<float.h>
#include<stack>
#include<math.h>
#include<queue>
#include<unordered_set>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* removeElements(ListNode* head, int val) {
		if (!head) return NULL;
		ListNode* p = head, *q = head, *ans = NULL;
		while (p){
			if (p->val != val) {
				if (!ans) q = ans = p;
				else {
					q->next = p;
					q = p;
				}
			}
			p = p->next;
		}
		q->next = NULL;
		return ans;
	}
	bool isIsomorphic(string s, string t) {
		int len_s = s.size();
		int len_t = t.size();
		if (len_s != len_t) return false;
		map<char, vector<int>> m_s;
		map<char, vector<int>> m_t;
		for (int i = 0; i < len_t; i++){
			m_s[s[i]].push_back(i);
			m_t[t[i]].push_back(i);
		}
		int *a_s = new int[len_s];
		memset(a_s, 0, len_s*sizeof(int));
		vector<int> v_s, v_t;
		for (int i = 0; i < len_t; i++) {
			if (!a_s[i]) {
				v_s = m_s[s[i]];
				v_t = m_t[t[i]];
				if (v_s.size() != v_t.size()) return false;
				for (int j = 0; j < v_s.size(); j++) {
					if (v_s[j] != v_t[j]) return false;
					a_s[v_s[j]] = 1;
				}
			}
		}
		return true;
	}
};
union
{
	int i;
	char a[2];
}*p, u;
class A
{
	int i;
	/*union U
	{
		char buff[13];
		int i;
	}u;*/
	void foo(){}
	typedef char* (*f)(void*);
	enum{ red, green, blue } color;
}a1;
int func(unsigned int i)
{
	unsigned int temp = i;
	temp = (temp & 0x55555555) + ((temp & 0xaaaaaaaa) >> 1);
	temp = (temp & 0x33333333) + ((temp & 0xccccccccc) >> 2);
	temp = (temp & 0x0f0f0f0f) + ((temp & 0xf0f0f0f0 >> 4));
	temp = (temp & 0xff00ff) + ((temp & 0xff00fff00) >> 8);
	temp = (temp & 0xffff) + ((temp & 0xffff0000) >> 16);
	return  temp;
}
int main() {
	Solution so;
	cout << so.isIsomorphic("foo", "bar") << endl;
	int a = 0010; p = &u;
	p->a[0] = 0x1;
	p->a[1] = 0x2;
	cout << p->i << endl; 
	const char str1[] = "abc";
	const char str2[] = "abc";
	const char *p1 = "abc";
	const char *p2 = "abc";
	cout << (int)str1 << endl;
	cout << (int)str2 << endl;
	union Test
	{
		char a[4];
		short b;
	};
	cout << endl << func(0x11530828) << endl;
	return 0;
}