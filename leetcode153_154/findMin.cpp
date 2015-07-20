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
	//1
	int findMin(vector<int>& nums) {

	}
	ListNode* reverseList1(ListNode* head) {
		if (!head->next) { ans = head; return head; }
		reverseList1(head->next)->next = head;
		return head;
	}
	ListNode* reverseList(ListNode* head) {
		if (!head || !head->next) return head;
		reverseList1(head)->next = NULL;
		return ans;
	}
private:
	ListNode *ans;
};

int main(void) {
	ListNode *l1 = new ListNode(2);
	ListNode *l2 = new ListNode(1);
	l1->next = l2;
	Solution so;
	so.reverseList(l1);
	return 0;
}