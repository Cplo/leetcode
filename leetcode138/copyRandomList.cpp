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

//Definition for singly-linked list with a random pointer.
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		if (!head) return NULL;
		map<int, RandomListNode*> m_node;
		RandomListNode *ans_head = NULL;
		RandomListNode *p = head, *ans_p = NULL;
		while (p) {
			RandomListNode *node;
			if (m_node.find(p->label) == m_node.end()) { node = new RandomListNode(p->label); m_node[p->label] = node;}
			else node = m_node[p->label];
			if (p->random) {
				if (m_node.find(p->random->label) == m_node.end()) {
					node->random = new RandomListNode(p->random->label);
					m_node[p->random->label] = node->random;
				}
				else {
					node->random = m_node[p->random->label];
				}
			}
			if (!ans_head) { ans_p = ans_head = node; }
			else { ans_p->next = node; ans_p = node; }
			p = p->next;
		}
		return ans_head;
	}
};

int main(void) {
	return 0;
}