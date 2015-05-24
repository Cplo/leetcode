#include<cstdio>
using namespace std;
#include<vector>
#include<map>
#include<string.h>
#include<queue>
//拓扑合法性检查（）
const int MAXM = 5000005;
const int MAXN = 100005;
//维护入度数组
int deg[MAXM];
int T, N, M;
//统计去除的入度为0的结点
int coun;
int pre, nex;
//queue<int> q_neightbor;
int q_neightbor[MAXN];
int start, rear;

int head[MAXN + 1] = { 0 };	// 表示头指针，初始化为0
int p[MAXM + 1];		// 表示指向的节点
int _next[MAXM + 1] = { 0 }; 	// 模拟指针，初始化为0
int edgecnt;			// 记录边的数量

void addedge(int u, int v) {	// 添加边(u,v)
	++edgecnt;
	p[edgecnt] = v;
	_next[edgecnt] = head[u];
	head[u] = edgecnt;
}

int main(void) {
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d%d", &N, &M);
		edgecnt = 0;
		memset(deg, 0, (N + 1)*sizeof(int));
		memset(head, 0, (MAXN + 1)*sizeof(int));
		memset(p, 0, (MAXM + 1)*sizeof(int));
		memset(_next, 0, (MAXM + 1)*sizeof(int));
		memset(q_neightbor, 0, (N + 1) * sizeof(int));
		
		for (int j = 0; j < M; j++) {
			scanf("%d%d", &pre, &nex);
			addedge(pre, nex);
			deg[nex]++;
		}
		start = rear = 0;
		//统计入度为0的结点，并加入队列；
		for (int j = 1; j <= N; j++) {
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
		coun == N ? printf("Correct\n") : printf("Wrong\n");
	}
	return 0;
}