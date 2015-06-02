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
//5
//2
//2
//5
int left_node[1000];
int right_node[1000];
class Solution {
public:
	void build(TreeNode* node, int i) {
		if (left_node[i] <= n&&left_node[i] >= 1){
			node->left = new TreeNode(left_node[i]);
			build(node->left, left_node[i]);
		}
		if (right_node[i] <= n&&right_node[i] >= 1){
			node->right = new TreeNode(right_node[i]);
			build(node->right, right_node[i]);
		}
	}
	void buildBST(vector<TreeNode*> &ans, int l, int r, int& cur, int parent) {
		/*if (cur == n) {
		TreeNode *root = new TreeNode(start_num);
		build(root, start_num);
		ans.push_back(root);
		return;
		}*/
		int temp = cur;
		for (int i = l; i <= r; i++) {
			memset(left_node + l, 0, (r - l + 1)*sizeof(int));
			memset(right_node + l, 0, (r - l + 1)*sizeof(int));
			cur = temp;
			if (parent == i)
				continue;
			if (parent > i) left_node[parent] = i;
			else right_node[parent] = i;
			cur++;
			if (cur == n) {
				TreeNode *root = new TreeNode(start_num);
				build(root, start_num);
				ans.push_back(root);
				continue;
			}
			if (l == i - 1) {
				left_node[i] = l;
				cur++;
				if (cur == n) {
					TreeNode *root = new TreeNode(start_num);
					build(root, start_num);
					ans.push_back(root);
					continue;
				}
			}
			if (i + 1 == r) {
				right_node[i] = r;
				cur++;
				if (cur == n) {
					TreeNode *root = new TreeNode(start_num);
					build(root, start_num);
					ans.push_back(root);
					continue;
				}
			}
			if (l<i - 1) buildBST(ans, l, i - 1, cur, i);
			if (i + 1<r) buildBST(ans, i + 1, r, cur, i);
			buildBST(ans, parent + 1, parent + n - cur, cur, parent);
			//memset(left_node + cur + 1, 0, (n-cur)*sizeof(int));
			//memset(right_node + cur + 1, 0, (n-cur)*sizeof(int));
		}
	}
	vector<TreeNode*> generateTrees(int n) {
		vector<TreeNode*> ans;
		if (!n) {
			ans.push_back(NULL);
			return ans;
		}
		if (n == 1) {
			TreeNode *root = new TreeNode(1);
			ans.push_back(root);
			return ans;
		}
		this->n = n;

		memset(left_node, 0, (n + 1)*sizeof(int));
		memset(right_node, 0, (n + 1)*sizeof(int));
		int cur = 1;
		start_num = 1;
		buildBST(ans, 2, n, cur, 1);

		memset(left_node, 0, (n + 1)*sizeof(int));
		memset(right_node, 0, (n + 1)*sizeof(int));
		cur = 2;
		start_num = 2;
		left_node[2] = 1;
		if (n == cur) {
			TreeNode *root = new TreeNode(start_num);
			build(root, start_num);
			ans.push_back(root);
		}
		else
			buildBST(ans, cur + 1, n, cur, cur);

		for (int i = 3; i <= n; i++) {
			cur = 1;
			start_num = i;
			memset(left_node, 0, (n + 1)*sizeof(int));
			memset(right_node, 0, (n + 1)*sizeof(int));
			buildBST(ans, 1, i - 1, cur, i);
		}
		return ans;
	}
private:
	int n;
	int start_num;
};

int main(void) {
	Solution so;
	so.generateTrees(5);
	return 0;
}