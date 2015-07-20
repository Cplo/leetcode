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

//Definition for a binary tree node.
struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool ancestor(TreeNode* root, TreeNode* p, vector<TreeNode*>& v) {
		if (root) {
			if (root == p) { v.push_back(p); return true; }
			if (ancestor(root->left, p, v) || ancestor(root->right, p, v)) { v.push_back(root); return true; }
		}
		return false;
	}
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		vector<TreeNode*> v_p;
		vector<TreeNode*> v_q;
		if (ancestor(root, p, v_p) && ancestor(root, q, v_q)) {
			int m = v_p.size();
			int n = v_q.size();
			int i = m - 1, j = n - 1;
			for (; i >= 0 && j >= 0; i--,j--) {
				if (v_p[i] != v_q[j]) 
					return v_p[i + 1];
			}
			return m<n ? v_p.front() : v_q.front();
		}
		return NULL;
	}
};

int main(void) {
	TreeNode *t = new TreeNode(2);
	TreeNode *t1 = new TreeNode(1);
	t->left = t1;
	Solution so;
	cout<<so.lowestCommonAncestor(t, t, t1)->val;
	return 0;
}