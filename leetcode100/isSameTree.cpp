#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<map>
#include<string.h>
#include<string>
#include<queue>
#include<float.h>

// Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if (p && q && (p->val == q->val)){
			if (isSameTree(p->left, q->left) == false)
				return false;
			if (isSameTree(p->right, q->right) == false)
				return false;
		}
		else{
			if (!q&&!p) return true;
			return false;
		}
		return true;
	}
	
};

