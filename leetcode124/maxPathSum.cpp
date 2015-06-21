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

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int maxPathSum(TreeNode* root, int& ans) {
			if (!(root->left) && !(root->right)) {
				ans = max(root->val, ans); 
				return root->val; 
			}
			int x;
			if (root->left&&root->right) {
				int left_ans = maxPathSum(root->left, ans);
				int right_ans = maxPathSum(root->right, ans);
				if (left_ans < 0 && right_ans < 0 && root->val < 0) {
					x = max(root->val, max(left_ans, right_ans));
					ans = max(x, ans);
				}
				else {
					if (root->val >= 0) {
						x = 0;
						if (left_ans > 0) x += left_ans;
						if (right_ans >0) x += right_ans;
						if (root->val > 0) x += root->val;
					}
					else{
						x = max(left_ans + right_ans + root->val, max(left_ans, right_ans));
					}
					ans = max(x, ans);
				}
				return max(root->val, max(left_ans, right_ans) + root->val);
			}
			else if (root->left) {
				x = maxPathSum(root->left, ans);
				int ans_temp = max(root->val, max(x, x + root->val));
				ans = max(ans, ans_temp);
				return max(root->val, x + root->val);
			}
			else {
				x = maxPathSum(root->right, ans);
				int ans_temp = max(root->val, max(x, x + root->val));
				ans = max(ans, ans_temp);
				return max(root->val, x + root->val);
			}
			
	}
	int maxPathSum(TreeNode* root) {
		if (root) {
			int ans = INT_MIN;
			return max(maxPathSum(root, ans), ans);
		}
		return 0;
	}
};

int main(void) {
	TreeNode*t1 = new TreeNode(1);
	TreeNode*t2 = new TreeNode(-2);
	TreeNode*t3 = new TreeNode(-3);
	TreeNode*t4 = new TreeNode(1);
	TreeNode*t5 = new TreeNode(3);
	TreeNode*t6 = new TreeNode(-2);
	TreeNode*t7 = new TreeNode(-1);
	t1->left = t2;
	t1->right = t3;
	t2->left = t4;
	t2->right = t5;
	t3->left = t6;
	t4->left = t7;
	Solution so;
	cout << so.maxPathSum(t1) << endl;;
	return 0;
}