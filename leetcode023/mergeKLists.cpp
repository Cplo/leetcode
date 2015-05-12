#include<iostream>
using namespace std;
#include<vector>
#include<list>
#include<algorithm>
// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 }; 
bool cmp_by_ListNode(const ListNode *left, const ListNode *right){
	 return left->val < right->val;
}

 //class Solution {
 //public:
	// ListNode *mergeKLists(vector<ListNode *> &lists) {
	//	 int size = lists.size();
	//	 // ListNode *ans_final = NULL;
	//	 ListNode *ans = NULL;
	//	 ListNode *ans_p = NULL;
	//	 vector<ListNode *> vecList;
	//	 for (int i = 0; i < size; i++){
	//		 if (lists[i]) { vecList.push_back(lists[i]); }
	//	 }
	//	 size = vecList.size();
	//	 if (!size) return NULL;
	//	 if (size == 1) return *(vecList.begin());
	//	 sort(vecList.begin(), vecList.end(), cmp_by_ListNode);
	//	 vector<ListNode *>::iterator it;
	//	 ListNode *k = NULL;	//k����ֵ�������ϴ�vecList��ͷֵ������Сֵ���ڽ�㣩
	//	 int val;
	//	 int flag;				//0����ʾk����ֵ��vecList���κν��ֵ��С����ʱֱ�ӽ�k������ans�б��У�����k����ָ��k->next
	//	 while (vecList.size() > 1 || vecList.size() == 1 && k){
	//		 it = vecList.begin();
	//		 val = (*it)->val;
	//		 flag = 1;
	//		 if (k){
	//			 if (k->val <= val){
	//				 val = k->val;
	//				 flag = 0;
	//			 }
	//			 else{
	//				 //����1������vecList������,���Ӷ�O(n*logn),nΪvecList�����Ŀ,����ʱ��154 ms
	//				 /*vecList.push_back(k);
	//				 sort(vecList.begin(), vecList.end(), cmp_by_ListNode);*/
	//				 //��ΪvecList����������ģ�������������ֻҪ��kֵ�������λ�ü���ʹ��vecList���򣨼��ټ�������
	//				 //����2��ֱ�Ӳ��룬���Ҹ��Ӷ�ΪO(n)�����븴�Ӷ�Ҳ��O(n)[��Ϊ�������ڴ棬�����Ԫ����Ҫ�ڳ��ռ�]������ʱ��65 ms
	//				 /*vector<ListNode *>::iterator loc;
	//				 for (loc = vecList.begin(); loc != vecList.end(); loc++){
	//				 if ((*loc)->val > k->val) break;
	//				 }
	//				 if (loc != vecList.end()){
	//					 vecList.insert(loc, k);
	//				 }
	//				 else{
	//					 vecList.push_back(k);
	//				 }*/
	//				 //����2�Ľ���ʹ�ö��ַ����ң�����ʱ�䣺60 ms
	//				 int l = 0, r = vecList.size() - 1;
	//				 int mid =( l + r) / 2;
	//				 while (l<r){
	//					 if (k->val < vecList[mid]->val)
	//						 r = mid;
	//					 else
	//						 l = mid;
	//					 mid = (l + r) / 2;
	//					 if (mid == l) break;
	//				 }vector<ListNode *>::iterator loc;
	//				 if (k->val >= vecList[r]->val) vecList.push_back(k);
	//				 else if (r - l == 1 && k->val > vecList[l]->val){
	//					 loc = vecList.begin() + r;
	//					 vecList.insert(loc, k);
	//				 }
	//				 else{
	//					 loc = vecList.begin() + l;
	//					 vecList.insert(loc, k);
	//				 }
	//			 }
	//		 }
	//		 ListNode *node = new ListNode(val);
	//		 if (!ans) ans_p = ans = node;
	//		 else {
	//			 ans_p->next = node; ans_p = node;
	//		 }
	//		 if (flag){
	//			 k = (*it)->next;
	//			 vecList.erase(it);
	//		 }
	//		 else k = k->next;
	//	 }
	//	 //if (vecList.size() == 1 && (!k)){
	//		 if (!ans) ans = *vecList.begin();
	//		 else ans_p->next = *vecList.begin();
	//	// }
	//	 return ans;
	// }
 //};
class Solution {
public:
	ListNode *mergeKLists(vector<ListNode *> &lists) {
		int size = lists.size();
		ListNode *ans = NULL;
		ListNode *ans_p = NULL;
		vector<ListNode *> vecList;
		for (int i = 0; i < size; i++){
			if (lists[i]) { vecList.push_back(lists[i]); }
		}
		size = vecList.size();
		if (!size) return NULL;
		if (size == 1) return vecList.front();
		int i = 0;
		while (i<size)
		{
			ListNode*p = vecList[i++];
			while (p->next){
				vecList.push_back(p->next);
				p = p->next;
			}
		}
		sort(vecList.begin(), vecList.end(), cmp_by_ListNode);
		size = vecList.size();
		i = 0;
		while (i<size){
			ListNode * node = new ListNode(vecList[i]->val);
			if (!ans) ans_p = ans = node;
			else { ans_p->next = node; ans_p = node; }
			i++;
		}
		return ans;
	}
};
int main(){
	ListNode *a = new ListNode(1);
	ListNode *b = new ListNode(2);
	ListNode *c = new ListNode(2);
	ListNode *d = new ListNode(1);
	ListNode *e = new ListNode(1);
	//ListNode *f = new ListNode(2);
	//ListNode *f = NULL;
	//[{7},{49},{73},{58},{30},{72},{44},{78},{23},{9},{40},{65},{92},{42},{87},{3},{27},{29},{40},{12},{3},{69},{9},{57},{60},{33},{99}
	vector<ListNode*> lists;
	//lists.push_back(f);
	lists.push_back(b);
	lists.push_back(c);
	lists.push_back(a);
	lists.push_back(e);
	lists.push_back(d);
	Solution so;
	ListNode *ans = so.mergeKLists(lists);
	while (ans){
		cout << ans->val << endl;
		ans = ans->next;
	}
	return 0;
}