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

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/ 
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	bool isValidBST(TreeNode* root) {
		vector<int> ans;
		if (!root) return true;
		stack<TreeNode*> s;
		while (root) {
			s.push(root);
			root = root->left;
		}
		while (!s.empty()) {
			TreeNode * t = s.top();
			s.pop();
			if (!ans.empty()) if (t->val <= ans.back()) return false; 
			ans.push_back(t->val);
			if (t->right) {
				t = t->right;
				while (t){
					s.push(t);
					t = t->left;
				}
			}
		}
		return true;
	}
};

int main(void){
	return 0;
}