#include<cstdio>
using namespace std;
#include<vector>
#include<map>
#include<string.h>
#include<queue>
//���˺Ϸ��Լ�飨��
const int MAXM = 5000005;
const int MAXN = 100005;
//ά���������
int deg[MAXM];
int T, N, M;
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
		//ͳ�����Ϊ0�Ľ�㣬��������У�
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