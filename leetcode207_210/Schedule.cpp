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
//���˺Ϸ��Լ�飨��
const int MAXM = 5000005;
const int MAXN = 100005;
//ά���������
int deg[MAXM];
//ͳ��ȥ�������Ϊ0�Ľ��
int coun;
int pre, nex;
//queue<int> q_neightbor;
int q_neightbor[MAXN];
int start, rear;

int head[MAXN + 1] = { 0 };	// ��ʾͷָ�룬��ʼ��Ϊ0
int p[MAXM + 1];		// ��ʾָ��Ľڵ�
int _next[MAXM + 1] = { 0 }; 	// ģ��ָ�룬��ʼ��Ϊ0
int edgecnt;			// ��¼�ߵ�����

void addedge(int u, int v) {	// ��ӱ�(u,v)
	++edgecnt;
	p[edgecnt] = v;
	_next[edgecnt] = head[u];
	head[u] = edgecnt;
}
class Solution {
public:
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		int n = prerequisites.size();
		edgecnt = 0;
		memset(deg, 0, (numCourses + 1)*sizeof(int));
		memset(head, 0, (MAXN + 1)*sizeof(int));
		memset(p, 0, (MAXM + 1)*sizeof(int));
		memset(_next, 0, (MAXM + 1)*sizeof(int));
		memset(q_neightbor, 0, (numCourses + 1) * sizeof(int));
		for (int i = 0; i < n; i++) {
			addedge(prerequisites[i].second, prerequisites[i].first);
			deg[prerequisites[i].first]++;
		}
		start = rear = 0;
		//ͳ�����Ϊ0�Ľ�㣬��������У�
		for (int j = 0; j < numCourses; j++) {
			if (!deg[j])  {
				//q_neightbor.push(j);
				q_neightbor[rear++] = j;
			}
		}
		coun = 0;
		//while (!q_neightbor.empty()) {
		while (start < rear) {
			//int lesson = q_neightbor.front();
			int lesson = q_neightbor[start++];
			//q_neightbor.pop();
			coun++;
			for (int k = head[lesson]; k; k = _next[k]){
				deg[p[k]]--;
				if (!deg[p[k]])	q_neightbor[rear++] = p[k];
			}
		}
		return coun == numCourses ? true : false;
	}
	vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<int> ans;
		int n = prerequisites.size();
		edgecnt = 0;
		memset(deg, 0, (numCourses + 1)*sizeof(int));
		memset(head, 0, (MAXN + 1)*sizeof(int));
		memset(p, 0, (MAXM + 1)*sizeof(int));
		memset(_next, 0, (MAXM + 1)*sizeof(int));
		memset(q_neightbor, 0, (numCourses + 1) * sizeof(int));
		for (int i = 0; i < n; i++) {
			addedge(prerequisites[i].second, prerequisites[i].first);
			deg[prerequisites[i].first]++;
		}
		start = rear = 0;
		//ͳ�����Ϊ0�Ľ�㣬��������У�
		for (int j = 0; j < numCourses; j++) {
			if (!deg[j])  {
				//q_neightbor.push(j);
				q_neightbor[rear++] = j;
			}
		}
		coun = 0;
		//while (!q_neightbor.empty()) {
		while (start < rear) {
			//int lesson = q_neightbor.front();
			int lesson = q_neightbor[start++];
			ans.push_back(lesson);
			//q_neightbor.pop();
			coun++;
			for (int k = head[lesson]; k; k = _next[k]){
				deg[p[k]]--;
				if (!deg[p[k]])	q_neightbor[rear++] = p[k];
			}
		}
		if (coun == numCourses) return ans;
		else { ans.clear(); return ans; }
	}
};

int main(void){
	Solution so;
	vector<pair<int, int>> v_pair;
	pair<int, int> point(1, 0);
	pair<int, int> point1(0, 1);
	v_pair.push_back(point);
	v_pair.push_back(point1);
	so.findOrder(3, v_pair);
	return 0;
}