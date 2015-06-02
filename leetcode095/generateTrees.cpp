#include<iostream>
#include<vector>
#include<string>
#include<string.h>
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
	vector<TreeNode*> generateTrees(int l, int r){
		vector<TreeNode*> ans;
		if (l == r) {
			TreeNode* node = new TreeNode(l);
			ans.push_back(node);
			return ans;
		}
		vector<TreeNode*> subtree_left;
		vector<TreeNode*> subtree_right;
		for (int i = l; i <= r; i++) {
			subtree_left.clear();
			subtree_right.clear();
			if (l <= i - 1) subtree_left = generateTrees(l, i - 1);
			if (i + 1 <= r) subtree_right = generateTrees(i + 1, r);
			if (subtree_left.empty()) {
				for (auto x : subtree_right) {
					TreeNode* node = new TreeNode(i);
					node->right = x;
					ans.push_back(node);
				}
				continue;
			}
			if (subtree_right.empty()) {
				for (auto x : subtree_left) {
					TreeNode* node = new TreeNode(i);
					node->left = x;
					ans.push_back(node);
				}
				continue;
			}
			for (auto x : subtree_left) {
				for (auto y : subtree_right) {
					TreeNode* node = new TreeNode(i);
					node->left = x;
					node->right = y;
					ans.push_back(node);
				}
			}
		}
		return ans;
	}
	vector<TreeNode*> generateTrees(int n) {
		vector<TreeNode*> ans;
		if (!n) {
			ans.push_back(NULL);
			return ans;
		}
		ans = generateTrees(1, n);
		return ans;
	}
};

int main(void) {
	Solution so;
	so.generateTrees(4);
	return 0;
}