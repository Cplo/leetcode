#include<iostream>
#include<vector>
#include<string>
#include<string.h>
#include<algorithm>
#include<map>
using namespace std;
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	/*ListNode* deleteDuplicates(ListNode* head) {
		ListNode *p = head, *q=NULL;
		head = NULL;
		while (p)
		{
			if (p->next && (p->val == (p->next->val))) {
				int val = p->val;
				while (p&&p->val == val) p = p->next;
				continue;
			}
			if (!head) q = head = p;
			else {
				q->next = p;
				q = p;
			}
			p = p->next;
		}
		if(q) q->next = NULL;
		return head;
	}*/
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode *p = head, *q = NULL;
		head = NULL;
		while (p)
		{
			if (!head) q = head = p;
			else {
				q->next = p;
				q = p;
			}
			while (p->next && (p->val == (p->next->val))) p = p->next;
			p = p->next;
		}
		if (q) q->next = NULL;
		return head;
	}
	ListNode* buildList(int a[], int n) {
		ListNode *head=NULL, *p;
		for (int i = 0; i < n; i++) {
			ListNode* node = new ListNode(a[i]);
			if (!head) head = p = node;
			else {
				p->next = node;
				p = node;
			}
		}
		return head;
	}
};
int main(void) {
	int a[] = { 1, 1, 2, 3, 3, 4, 4 };
	Solution so;
	ListNode *head = so.buildList(a, 7);
	so.deleteDuplicates(head);
	return 0;
}