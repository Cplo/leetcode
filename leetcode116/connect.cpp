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
using namespace std;

//Definition for binary tree with next pointer.
struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> ans;
		if (rowIndex<0) return ans;
		ans.push_back(1);
		int pre,cur;
		for (int i = 1; i < rowIndex + 1; i++) {
			for (int j = 0; j <= i; j++){
				if (j == i) ans.push_back(1);
				else if (j == 0) pre = ans[j] = 1;
				else {
					cur = ans[j];
					ans[j] += pre;
					pre = cur;
				}
			}
		}
		return ans;
	}
	void connect(TreeLinkNode *root) {
		if (!root) return;
		queue<TreeLinkNode*> q;
		queue<int> q_level;
		q.push(root);
		q_level.push(1);
		TreeLinkNode* p_ptr = NULL;
		int cur_level = 0;
		while (!q.empty()) {
			TreeLinkNode * node = q.front();
			int level = q_level.front();
			q.pop(); q_level.pop();
			if (level == cur_level) {
				p_ptr->next = node;
				p_ptr = node;
			}
			else {
				p_ptr = node;
				cur_level = level;
			}
			if (node->left) {
				q.push(node->left);
				q_level.push(level + 1);
			}
			if (node->right) {
				q.push(node->right);
				q_level.push(level + 1);
			}
		}
	}
};

int main(void){
	Solution so;
	so.getRow(3);
	return 0;
}