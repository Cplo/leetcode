#include<iostream>
using namespace std;

// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
//运行时间：38ms
class Solution {
public:
	ListNode *reverseKGroup(ListNode *head, int k) {
		if (!head) return NULL;
		if (k<=1) return head;
		ListNode *ans = NULL;
		ListNode *ans_p = head;
		ListNode *p = head;//前进！
		ListNode *p1;
		ListNode *q = head;
		ListNode *x;
		ListNode *y;
		int count ;
		while (1){
			count = 0;
			p1 = p;
			while (p&&count < k){
				count++;
				p = p->next;
			}
			if (count < k) {
				if (!ans)	ans = p1; 
				else{ ans_p->next = p1; }
				break;
			}
			else{
				x = y = q->next;
				count = 1;
				while (count < k){
					x = x->next;
					y->next = q;
					q = y;
					y = x;
					count++;
				}
				if (!ans) { ans = q; ans_p = p1; }
				else { ans_p->next = q; ans_p = p1; }
				q = p;
			}
			if (!p) break;
		}
		return ans;
	}
};
int main(){
	ListNode *a = new ListNode(1);
	ListNode *b = new ListNode(2);
	ListNode *c = new ListNode(3);
	ListNode *d = new ListNode(4);
	ListNode *f = new ListNode(5);
	ListNode *g = new ListNode(6);
	ListNode *h = new ListNode(7);
	a->next = b;
	b->next = c;
	c->next = d;
	d->next = f;
	f->next = g;
	g->next = h;
	Solution so;
	ListNode *ans = so.reverseKGroup(a,2);
	while (ans){
		cout << ans->val << endl;
		ans = ans->next;
	}
	return 0;
}