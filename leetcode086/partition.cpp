#include<cstdio>
#include<vector>
#include<string>
#include<string.h>
#include<algorithm>
#include<map>
#include<float.h>
#include<stack>
#include<queue>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* partition(ListNode* head, int x) {
		ListNode *p = head;
		ListNode *l = NULL, *l_it = NULL, *g = NULL, *g_it = NULL;
		while (p) {
			ListNode* node = new ListNode(p->val);
			if (p->val < x) {
				
				if (!l) l_it = l = node;
				else {
					l_it->next = node;
					l_it = node;
				}
			}
			else {
				if (!g) g_it = g = node;
				else {
					g_it->next = node;
					g_it = node;
				}
			}
			p = p->next;
		}
		if (l_it) {
			l_it->next = g;
			return l;
		}
		else {
			return g;
		}
	}
};

int main(void)	{

	return 0;
}