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
	void sumNumbers(int &ans, TreeNode* root, int cur) {
		if (root) {
			if (!(root->left) && !(root->right)) {
				ans += (cur * 10 + root->val);
			}
			sumNumbers(ans, root->left, cur * 10 + root->val);
			sumNumbers(ans, root->right, cur * 10 + root->val);
		}
	}
	int sumNumbers(TreeNode* root) {
		int ans = 0;
		sumNumbers(ans, root, 0);
		return ans;
	}
};

int main(void) {

	return 0;
}