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
	void reorderList(ListNode* head) {
		if (!head || !head->next) return;
		ListNode* p = head;
		vector<ListNode*> v_Node;
		while (p) {
			v_Node.push_back(p);
			p = p->next;
		}
		int n = v_Node.size();
		p = NULL;
		head = NULL;
		for (int i = 0; i < n / 2; i++) {
			v_Node[i]->next = v_Node[n - 1 - i];
			if (!head) {
				head = v_Node[i];
				p = v_Node[n - 1 - i];
			}
			else {
				p->next = v_Node[i];
				p = v_Node[n - 1 - i];
			}
		}
		if (n % 2) { v_Node[n / 2]->next = NULL; p->next = v_Node[n / 2]; }
		else { v_Node[n / 2]->next = NULL; }
	}
};

int main(void){
	ListNode*p1 = new ListNode(1);
	ListNode*p2 = new ListNode(2);
	ListNode*p3 = new ListNode(3);
	p1->next = p2; p2->next = p3;
	Solution so; so.reorderList(p1);
	return 0;
}