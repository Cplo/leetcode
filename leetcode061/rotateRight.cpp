#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<map>
#include<string.h>
#include<string>
#include<queue>
#include<float.h>


// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		if (!k)  return head;
		if (!head) return head;
		vector<ListNode*> v;
		ListNode *p = head;
		while (p){
			v.push_back(p);
			p = p->next;
		}
		int n = v.size();
		k = k % n;
		if (!k) return head;
		v[n - k - 1]->next = NULL;
		v[n - 1]->next = head;
		return v[n - k];
	}
};