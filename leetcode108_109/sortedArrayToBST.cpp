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

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	TreeNode* buildTree(vector<int>& nums, int l, int r) {
		if (l > r) return NULL;
		if (l == r) {
			return new TreeNode(nums[l]);
		}
		int mid = (l + r) / 2;
		TreeNode *node = new TreeNode(nums[mid]);
		if (mid - 1 >= l) {
			node->left = buildTree(nums, l, mid - 1);
		}
		if (mid + 1 <= r){
			node->right = buildTree(nums, mid + 1, r);
		}
		return node;
	}
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		int n = nums.size();
		return buildTree(nums, 0, n - 1);
	}
	TreeNode* sortedListToBST(ListNode* head) {
		vector<int> nums;
		ListNode*p = head;
		while (p) {
			nums.push_back(p->val);
			p = p->next;
		}
		int n = nums.size();
		return buildTree(nums, 0, n - 1);
	}    
	void minDepth(TreeNode* root, int dep, int &ans){
		if (!root){
			ans = 0; return;
		}
		if (root->left) minDepth(root->left, dep + 1, ans);
		if (root->right) minDepth(root->right, dep + 1, ans);
		if ((root->left == NULL) && (root->right == NULL)) ans = min(ans, dep);
	}
	int minDepth(TreeNode* root) {
		int ans = INT_MAX;
		minDepth(root, 1, ans);
		return ans;
	}
	int calBalanced(bool &ans, TreeNode*root, int depth) {
		if (root){
			int left_dep = 0, right_dep = 0;
			if (root->left) {
				left_dep = calBalanced(ans, root->left, 1 + depth);
				left_dep++;
			}
			if (root->right) {
				right_dep = calBalanced(ans, root->right, 1 + depth);
				right_dep++;
			}
			if (abs(left_dep - right_dep) >= 2) ans = false;
			return max(left_dep, right_dep);
		}
		else return 0;
	}
	bool isBalanced(TreeNode* root) {
		bool ans = true;
		calBalanced(ans, root, 1);
		return ans;
	}
	bool pathSum(vector<int>&cur, int& goal, int cur_sum, TreeNode* root) {
		if (root) {
			cur_sum += root->val;
			if ((root->left == NULL) && (root->right == NULL)) {
				if (cur_sum == goal) {
					return true;
				}
				return false;
			}
			cur.push_back(root->val);
			if (root->left) {
				if (pathSum(cur, goal, cur_sum, root->left)) return true;
			}
			if (root->right){
				if (pathSum(cur, goal, cur_sum, root->right))  return true;
			}
			cur.pop_back();
		}
		return false;
	}
	bool hasPathSum(TreeNode* root, int sum) {
		vector<int> cur;
		return pathSum(cur, sum, 0, root);
	}
	void pathSum(vector<vector<int>>&ans, vector<int>&cur, int& goal, int cur_sum, TreeNode* root) {
		if (root) {
			cur_sum += root->val;
			if ((root->left == NULL) && (root->right == NULL)) {
				if (cur_sum == goal) {
					vector<int> v;
					for (auto k : cur) v.push_back(k);
					v.push_back(root->val);
					ans.push_back(v); 
				}
				return;
			}
			cur.push_back(root->val);
			if (root->left) {
				pathSum(ans, cur, goal, cur_sum, root->left);
			}
			if (root->right){
				pathSum(ans, cur, goal, cur_sum, root->right);
			}
			cur.pop_back();
		}
	}
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<int> cur;
		vector<vector<int>> ans;
		pathSum(ans, cur, sum, 0, root);
		return ans;
	}
	void flatten(TreeNode* root, vector<int>& v) {
		if (root) {
			v.push_back(root->val);
			if (root->left) {
				flatten(root->left, v);
			}
			if (root->right) {
				flatten(root->right, v);
			}
		}
	}
	void flatten(TreeNode* root) {
		vector<int> v;
		flatten(root, v);
		TreeNode *p = root;

		for (int i = 1; i < v.size();i++) {
			p->left = NULL;
			if (p->right) p->right->val = v[i];
			else p->right = new TreeNode(v[i]);
			p = p->right;
		}
		if (p) p->left = NULL;
	}
};
int main(void) {
	int a[10] = { 1, 2, 3, 4, 5 };
	vector<int> v(a, a + 5);
	Solution so;
	TreeNode* ans = so.sortedArrayToBST(v);
	TreeNode* t1 = new TreeNode(1);
	TreeNode* t2 = new TreeNode(2);
	TreeNode* t3 = new TreeNode(3);
	TreeNode* t4 = new TreeNode(4);
	TreeNode* t5 = new TreeNode(5);
	TreeNode* t6 = new TreeNode(6);
	TreeNode* t7 = new TreeNode(7);
	t1->left = t2;
	int depth = so.minDepth(t1);
	bool b = so.isBalanced(t1);
	so.pathSum(NULL, 1);
	so.flatten(t1);
	return 0;
}