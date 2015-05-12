#include<iostream>
using namespace std;

// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
		ListNode *ans=NULL;
		ListNode *p;
		while (l1&&l2){
			if (l1->val < l2->val) {
				if (!ans) p = ans = l1;
				else {
					p->next = l1;
					p = p->next;
				}
				l1 = l1->next;
			}
			else {
				if (!ans) p = ans = l2;
				else {
					p->next = l2;
					p = p->next;
				}
				l2 = l2->next;
			}
		}
		if (l1) {
			if (ans)
				p->next = l1;
			else
				ans = l1;
		}
		if (l2) {
			if (ans)
				p->next = l2;
			else
				ans = l2;
		}
		return ans;
	}
};

int main(){
	return 0;
}