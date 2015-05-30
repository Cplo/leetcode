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
		if (l > r) return;
		if (l == r) {
			right_node[l] = left_node[l] = 0;
			if (parent > l) left_node[parent] = l;
			else right_node[parent] = l;
			cur++;
			if (cur == n) {
				TreeNode *root = new TreeNode(start_num);
				build(root, start_num);
				ans.push_back(root);
				if (parent < l) right_node[parent] = 0;
				else left_node[parent] = 0;
			}
			if (cur == start_num) {
				buildBST(ans, start_num + 1, n, cur, start_num);
			}
			return;
		}
		memset(left_node+l, 0, (r - l + 1)*sizeof(int));
		memset(right_node + l, 0, (r - l + 1)*sizeof(int));
		int temp = cur;
		for (int i = l; i <= r; i++) {
			cur = temp;
			if (parent > i) left_node[parent] = i;
			else right_node[parent] = i;
			cur++;
			buildBST(ans, l, i - 1, cur, i);
			buildBST(ans, i + 1, r, cur, i);
			//left_node[parent] = right_node[parent] = 0;
			if (parent < i) right_node[parent] = 0;
			else left_node[parent] = 0;
		}
	}
	vector<TreeNode*> generateTrees(int n) {
		vector<TreeNode*> ans;
		if (!n) return ans;
		if (n == 1) {
			TreeNode *root = new TreeNode(1);
			ans.push_back(root);
			return ans;
		}
		this->n = n;
		int cur = 1;
		memset(left_node, 0, (n + 1)*sizeof(int));
		memset(right_node, 0, (n + 1)*sizeof(int));
		start_num = 1;
		buildBST(ans, 2, n, cur, 1);
		for (int i = 2; i <= n; i++) {
			start_num = i;
			cur = 1;
			memset(left_node, 0, (n + 1)*sizeof(int));
			memset(right_node, 0, (n + 1)*sizeof(int));
			buildBST(ans, 1, i-1, cur, i);
		}
		return ans;
	}
private:
	int n;
	int start_num;
};

int main(void) {
	Solution so;
	so.generateTrees(4);
	return 0;
}
