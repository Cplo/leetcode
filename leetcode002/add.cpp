#include<iostream>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		ListNode * answer = NULL;
		ListNode * p1 = l1, *p2 = l2,*ansp;
		int sum;
		int carry=0;
		while (p1!=NULL&&p2!=NULL)
		{
			sum = p1->val + p2->val + carry;
			if (sum > 9) { sum = sum % 10; carry = 1; }
			else carry = 0;
			ListNode * node = new ListNode(sum);
			if (!answer) ansp = answer = node;
			else
			{
				ansp->next = node;
				ansp = ansp->next;
			}
			p1 = p1->next;
			p2 = p2->next;
			//cout << sum << endl;
		}
		ListNode *p = NULL;
		if (p1) p = p1;
		if (p2) p = p2;
		while (p)
		{
			sum = p->val + carry;
			if (sum > 9) { sum = sum % 10; carry = 1; }
			else carry = 0;
			ListNode * node = new ListNode(sum);
			if (!answer) ansp = answer = node;
			else
			{
				ansp->next = node;
				ansp = ansp->next;
			}
			p = p->next;
		}
		if (carry)
		{
			ListNode * node = new ListNode(carry);
			ansp->next = node;
		}
		return answer;
	}
};

int main()
{
	/*ListNode * l1=NULL, *l2=NULL;
	ListNode * p1 = NULL, *p2 = NULL;
	ListNode * n1, *n2;
	int n,x1,x2;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x1 >> x2;
		n1 = new ListNode(x1);
		n2 = new ListNode(x2);
		if (l1 == NULL) { p1 = l1 = n1; p2 = l2 = n2; }
		else { p1->next = n1; p1 = p1->next; p2->next = n2; p2 = p2->next; }
	}
	Solution so;
	so.addTwoNumbers(l1, l2);*/
	int a[3][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int*ptr1 = (int*)(&a[0] + 2);
	int*ptr2 = (int*)((int)a + 1);
	printf("%x,%x", ptr1[-1], *ptr2);
	return 0;
}