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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool count(TreeNode* root, int& ans, int& level, int cur) {
		if (root){
			if (level == cur) {
				if (root->left) ans++;
				else return true;
				if (root->right) ans++;
				else return true;
			}
			else {
				if (count(root->left, ans, level, cur + 1)) return true;
				if (count(root->right, ans, level, cur + 1)) return true;
			}
		}
		return false;
	}
	bool test(TreeNode* root, int n, int& level) {
		string s;
		char ch;
		while (n) {
			ch = n & 1 + '0';
			s = ch + s;
			n = n >> 1;
		}
		int len = s.length();
		int l_size = level - 1 - len;
		int i = 0;
		TreeNode *p = root;
		while (i < l_size) {
			p = p->left;
			i++;
		}
		for (int i = 0; i < len; i++){
			if (s[i] == '0') p = p->left;
			else p = p->right;
		}
		return p != NULL ? true : false;
	}
	int countNodes(TreeNode* root) {
		int l_level = 0, r_level = 0;
		TreeNode *p = root;
		while (p) {
			l_level++;
			p = p->left;
		}
		p = root;
		while (p) {
			r_level++;
			p = p->right;
		}
		int ans = pow(2, r_level) - 1;
		if (l_level != r_level){
			//通过二分法查找
			int n = pow(2, l_level - 1);
			int l = 0, r = n - 1,mid;
			while (l <= r) {
				mid = (l + r) / 2;
				int mask = 1 << (r_level - 1);
				TreeNode *p = root;
				while (mask) {
					if (mask&mid) p = p->right;
					else p = p->left;
					mask >>= 1;
				}
				if (p) l = mid + 1;
				else r = mid - 1;
			}
			return ans + l;
		}
		return ans;
	}
};

int main(void){
	TreeNode *p = new TreeNode(1);
	TreeNode *p1 = new TreeNode(2);
	TreeNode *p2 = new TreeNode(3);
	TreeNode *p3 = new TreeNode(4);
	TreeNode *p4 = new TreeNode(5);
	p->left = p1;
	p->right = p2;
	p1->left = p3;
	p1->right = p4;
	Solution so;
	cout << so.countNodes(p) << endl;
	return 0;
}