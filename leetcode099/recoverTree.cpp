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
		void recoverTree(vector<int> &ans, int& cur, TreeNode* root){
			if (!root) return;
			if (root->left) {
				recoverTree(ans, cur, root->left);
			}
			root->val = ans[cur++];
			if (root->right) {
				recoverTree(ans, cur, root->right);
			}
		}
		void recoverTree(TreeNode* root) {
			vector<int> ans;
			if (!root) return;
			stack<TreeNode*> s;
			TreeNode* p = root;
			while (p) {
				s.push(p);
				p = p->left;
			}
			while (!s.empty()) {
				TreeNode * t = s.top();
				s.pop();
				ans.push_back(t->val);
				if (t->right) {
					t = t->right;
					while (t){
						s.push(t);
						t = t->left;
					}
				}
			}
			sort(ans.begin(), ans.end());
			int cur = 0;
			recoverTree(ans, cur, root);
			return;
		}
	};

int main(void){
	Solution so;
	TreeNode* t1 = new TreeNode(1);
	TreeNode* t2 = new TreeNode(2);
	TreeNode* t3 = new TreeNode(3);
	TreeNode* t4 = new TreeNode(4);
	TreeNode* t5 = new TreeNode(5);
	t1->left = t2;
	t1->right = t3;
	t2->left = t4;
	t2->right = t5;
	so.recoverTree(t1);
	return 0;
}