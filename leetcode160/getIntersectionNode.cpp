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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if (!headA || !headB) return NULL;
		ListNode*p = headA;
		int countA = 0, countB = 0;
		while (p) {
			countA++;
			p = p->next;
		}
		p = headB;
		while (p) {
			countB++;
			p = p->next;
		}
		p = headA;
		if (countA > countB) {
			p = headA;
			while (countA > countB) {
				p = p->next;
				countA--;
			}
		}
		ListNode *q = headB;
		if (countB > countA) {
			while (countB > countA) {
				q = q->next;
				countB--;
			}
		}
		while (q&&p) {
			if (p == q) return p;
			p = p->next;
			q = q->next;
		}
		return NULL;
	}
	int trailingZeroes(int n) {
		if (!n) return 0;
		int ans = 0;
		while (n >= 5) {
			ans += n / 5;
			n /= 5;
		}
		return ans;
	}
	vector<string> summaryRanges(vector<int>& nums) {
		int n = nums.size();
		vector<string> ans;
		for (int i = 0; i < n;i++) {
			int start = i;
			while (i + 1 < n&&nums[i + 1] - nums[i] == 1) i++;
			char ch[100];
			if (i - start == 0) {
				sprintf(ch, "%d", nums[i]);
			}
			else {
				sprintf(ch, "%d->%d", nums[start], nums[i]);
			}
			string s(ch, strlen(ch));
			ans.push_back(s);
		}
		return ans;
	}
};

int main(void) {
	Solution so;
	//cout << so.trailingZeroes(15) << endl;
	int an[] = { 0, 1, 2, 4, 5, 7 };
	vector<int> v(an, an + 6);
	so.summaryRanges(v);
	/*for (int i = 1; i <= 12; i++) {
		cout << i <<" "<<so.trailingZeroes(i)<<" " << so.trailingZeroes1(i)<< endl;
	}*/
	cout << so.trailingZeroes(5) << endl;
	cout << so.trailingZeroes(50) << endl;
	cout << so.trailingZeroes(100) << endl;
	return 0;
}