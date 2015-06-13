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
// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int qu[100000];
class Solution {
public:
	void levelTraversal(vector<vector<int>> &ans, int level, TreeNode* root){
		if (root){
			if (level > ans.size()) {
				vector<int> v;
				v.push_back(root->val);
				ans.push_back(v);
			}
			else{
				ans[level - 1].push_back(root->val);
			}
			levelTraversal(ans, 1 + level, root->left);
			levelTraversal(ans, 1 + level, root->right);
		}
	}
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> ans;
		levelTraversal(ans, 1, root);
		return ans;
	}
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> ans;
		if (!root) return ans;
		queue<TreeNode*> node_q;
		queue<int> level_q;
		node_q.push(root);
		level_q.push(1);
		int index = 0;
		int count = 0;
		while (!node_q.empty()) {
			TreeNode *node = node_q.front();
			node_q.pop();
			int level = level_q.front();
			level_q.pop();
			if (level > ans.size()) {
				vector<int> v;
				v.push_back(node->val);
				ans.insert(ans.begin(), v);
			}
			else{
				ans.front().push_back(node->val);
			}
			if (node->left) {
				level_q.push(level + 1);
				node_q.push(node->left);
			}
			if (node->right){
				level_q.push(level + 1);
				node_q.push(node->right);
			}
		}
		return ans;
	}
	void zigzagLevelTraversal(vector<vector<int>> &ans, int level, TreeNode* root){
		if (root){
			if (level > ans.size()) {
				vector<int> v;
				v.push_back(root->val);
				ans.push_back(v);
			}
			else{
				if (level % 2)
					ans[level - 1].push_back(root->val);
				else
					ans[level - 1].insert(ans[level - 1].begin(), root->val);
			}
			zigzagLevelTraversal(ans, 1 + level, root->left);
			zigzagLevelTraversal(ans, 1 + level, root->right);
		}
	}
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> ans;
		zigzagLevelTraversal(ans, 1, root);
		return ans;
	}
	//TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

	//}
	int search(vector<int>& inorder, int l, int r, int target) {
		for (int i = l; i <= r; i++){
			if (target == inorder[i]) return i;
		}
	}
	TreeNode* buildTree(vector<int>& inorder, int in_l, int in_r, vector<int>& postorder, int post_l, int post_r) {
		if (in_l == in_r) {
			return new TreeNode(inorder[in_l]);
		}
		int idx = search(inorder, in_l, in_r, postorder[post_r]);
		TreeNode* node = new TreeNode(postorder[post_r]);
		int left_len = idx - in_l;
		int right_len = in_r - idx;
		if (left_len>0)
			node->left = buildTree(inorder, in_l, idx - 1, postorder, post_l, post_l + left_len - 1);
		if (right_len>0)
			node->right = buildTree(inorder, idx + 1, in_r, postorder, post_r - right_len, post_r - 1);
		return node;
	}
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		int n1 = inorder.size();
		int n2 = postorder.size();
		if (!n1) return NULL;
		return buildTree(inorder, 0, n1 - 1, postorder, 0, n2 - 1);
	}
};

int main(void) {
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
	so.zigzagLevelOrder(t1);
	int inorder[] = { 4,2,5,1,3};
	int postorder[] = { 4,5,2,3,1 };
	vector<int> in_order(inorder, inorder + 5);
	vector<int> post_order(postorder, postorder + 5);
	TreeNode* root = so.buildTree(in_order, post_order);
	so.levelOrderBottom(t1);
	return 0;
}