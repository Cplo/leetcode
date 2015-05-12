#include<iostream>
using namespace std;


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
//¼òµ¥Ìâ ¶÷¶÷ »Ø£¡
class Solution {
public:
	ListNode *removeNthFromEnd(ListNode *head, int n) {
		int i = 0;
		ListNode* ans;
		if (!head)return NULL;
		
		ListNode *p, *q;
		p = head;
		while (p){
			i++;
			p = p->next;
		}
		int goal = i - n + 1;
		p = q = head;
		i = 1;
		while (p){
			if (goal == 1) {
				return p->next;
			}
			i++;
			q = p;
			p = p->next;
			if (i == goal){
				q->next = p->next;
				break;
			}
		}
		return head;
	}
};