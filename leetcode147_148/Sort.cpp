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
	ListNode* sortList(ListNode* head) {
		if (!head || !head->next) return head;
		ListNode *ans = NULL;
		vector<int> v;
		ListNode*p = head;
		while (p) {
			v.push_back(p->val);
			p = p->next;
		}
		sort(v.begin(),v.end());
		int n = v.size();
		for (int i = 0; i < n; i++) {
			ListNode *node = new ListNode(v[i]);
			if (!ans) { p = ans = node; }
			else {
				p->next = node;
				p = node;
			}
		}
		return ans;
	}
	ListNode* insertionSortList(ListNode* head) {
		if (!head || !head->next) return head;
		ListNode *ans = head;
		ListNode *p = head->next;
		ans->next = NULL;
		while (p) {
			ListNode *x = p->next;
			p->next = NULL;
			ListNode* m = ans, *n = ans;
			if (p->val <= ans->val) { p->next = ans; ans = p; }
			else {
				while (m&&p->val > m->val) {
					n = m;
					m = m->next;
				}
				p->next = m;
				n->next = p;
			}
			p = x;
		}
		return ans;
	}
	void deleteNode(ListNode* node) {
		if (!node) return;
		*node = *(node->next);
	}
};

int main(void) {
	ListNode *p = new ListNode(3);
	ListNode *p1 = new ListNode(1);
	ListNode *p2 = new ListNode(4);
	ListNode *p3 = new ListNode(2);
	p->next = p1;
	p1->next = p2;
	p2->next = p3;
	Solution so;
	so.deleteNode(p2);
	so.insertionSortList(p);
	return 0;
}