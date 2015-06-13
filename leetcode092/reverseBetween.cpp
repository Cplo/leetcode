#include<cstdio>
#include<vector>
#include<string>
#include<string.h>
#include<algorithm>
#include<map>
#include<float.h>
#include<stack>
#include<math.h>
#include<queue>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* buildList(vector<int> v) {
		ListNode *head = NULL, *it = NULL;
		for (auto a : v) {
			ListNode *node = new ListNode(a);
			if (!head) head = it = node;
			else {
				it->next = node; it = node;
			}
		}
		return head;
	}
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		if (m == n) return head;
		int i = 0;
		ListNode *p = head,*q,*head_rev,*tail_rev;
		ListNode* tail = NULL;
		if (m - 1){
			while (p) {
				i++;
				if (i == m - 1){
					break;
				}
				p = p->next;
			}
			tail = p;
			p = p->next;
		}
		i = m;
		tail_rev = head_rev = p;
		q = p->next;
		i++;
		do {
			p = q->next;
			i++;
			q->next = head_rev;
			head_rev = q;
			q = p;
		} while (i <= n);
		if (!(m-1)) {
			tail_rev->next = p;
			return head_rev;
		}
		else {
			tail->next = head_rev;
			tail_rev->next = p;
			return head;
		}
	}
};

int main(void) {
	Solution so;
	int a[] = {1,2,3,4,5};
	vector<int> v(a, a + 5);
	ListNode *head = so.buildList(v);
	so.reverseBetween(head, 1, 5);
	return 0;
}