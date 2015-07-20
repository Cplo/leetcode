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
	bool isPalindrome(ListNode* head) {
		if (!head || !head->next) return true;
		ListNode*p = head; 
		int count = 0;
		while (p){
			count++;
			p = p->next;
		}
		ListNode*left = NULL;
		ListNode*right = NULL;
		ListNode*q=head;
		p = head->next;
		q->next = NULL;
		ListNode*r;
		int i = 1;
		if (count == 2) return p->val == q->val;
		while (p&&p->next) {
			r = p->next;
			if (i == count / 2) {
				left = q; right = p;
				break;
			}
			p->next = q;
			q = p;
			p = r;
			i++;
		}
		bool ans = true;
		p = left; q = count % 2 ? right->next : right;
		while (p&&q){
			if (p->val != q->val) ans =  false;
			p = p->next;
			q = q->next;
		}
		if (count == 3) {
			left->next = right;
		}
		else {
			p = left->next;
			q = left;
			r = p->next;
			left->next = right;
			do{
				p->next = q;
				q = p; p = r;
				if (r) r = r->next;
				else break;
			}while (1);
		}
		return ans;
	}
};

int main(void) {
	Solution so;
	ListNode *n1 = new ListNode(1);
	ListNode *n2 = new ListNode(2);
	ListNode *n3 = new ListNode(2);
	ListNode *n4 = new ListNode(2);
	ListNode *n5 = new ListNode(2);
	ListNode *n6 = new ListNode(1);
	n1->next = n2;
	n2->next = n3;
	//n3->next = n4;
	n4->next = n5;
	n5->next = n6;
	cout << so.isPalindrome(n1) << endl;
	while (n1){
		cout << n1->val << endl;
		n1 = n1->next;
	}
	return 0;
}