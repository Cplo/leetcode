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

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		if (!head) return NULL;
		ListNode *p = head, *p1 = head;
		int count = 1, count1 = 1;
		while (p && p1) {
			if (!(p1->next)) return NULL;
			if (!(p1->next->next)) return NULL;
			p1 = p1->next->next;
			p = p->next;
			if (p == p1) { 
				p = head;
				while (p&&p1&&p != p1) { p = p->next; p1 = p1->next; }
				return p;
			}
		}
		return NULL;
	}
	//bool hasCycle(ListNode *head) {
	//	if (!head) return false;
	//	unordered_set<ListNode *> un_set;
	//	ListNode *p = head;
	//	while (p) {
	//		if (un_set.find(p) == un_set.end()) un_set.insert(p);
	//		else return true;
	//		p = p->next;
	//	}
	//	return false;
	//}
	bool hasCycle(ListNode *head) {
		if (!head) return false;
		ListNode *p = head, *p1 = head;
		while (p && p1) {
			if (!(p1->next)) return false;
			if (!(p1->next->next)) return false;
			p1 = p1->next->next;
			p = p->next;
			if (p == p1) return true;
		}
		return false;
	}
};

int main(void) {
	ListNode * head = new ListNode(1);
	ListNode * head1 = new ListNode(2);
	ListNode * head2 = new ListNode(3);
	ListNode * head3 = new ListNode(4);
	head->next = head1;
	head1->next = head2;
	head2->next = head3;
	head3->next = head;
	Solution so;
	cout << so.detectCycle(head)->val;
	return 0;
}