#include<iostream>
using namespace std;

//Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode *swapPairs(ListNode *head) {
		if (!head) return NULL;
		if (!head->next) return head;
		ListNode *ans = NULL;
		ListNode *ans_p = NULL;
		ListNode *p = head, *q = head->next;
		while (1){
			p->next = q->next;
			q->next = p;
			if (!ans) { ans = q; ans_p = p; }
			else{ ans_p->next = q; ans_p = p; }
			p = p->next;
			if (p && p->next) {
				q = p->next;
			}
			else break;
		}
		return ans;
	}
};

int main(){
	ListNode *a = new ListNode(1);
	ListNode *b = new ListNode(2);
	ListNode *c = new ListNode(3);
	ListNode *d = new ListNode(4);
	a->next = b;
	b->next = c;
	c->next = d;
	Solution so;
	ListNode *ans = so.swapPairs(a);
	while (ans){
		cout << ans->val << endl;
		ans = ans->next;
	}
	return 0;
}