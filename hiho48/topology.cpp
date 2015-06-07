#include<cstdio>
#include<vector>
#include<string>
#include<string.h>
#include<algorithm>
#include<map>
#include<float.h>
#include<stack>
#include<queue>
using namespace std;
const int MAX_N = 100005;
const int MAX_M = 500005;
const int MOD = 142857;
map<int, vector<int> > map_neighbor;
queue<int> q_neightbor;
int vir[MAX_N];
int deg[MAX_N];
int main(void) {
	int M, N, K, A_i, u, v, ans = 0;
	scanf("%d%d%d", &N, &M, &K);
	memset(vir, 0, (N + 1)*sizeof(int));
	memset(deg, 0, (N + 1)*sizeof(int));
	for (int i = 0; i < K; i++){
		scanf("%d", &A_i);
		vir[A_i] = 1;
	}
	for (int i = 0; i < M; i++) {
		scanf("%d%d", &u, &v);
		map_neighbor[u].push_back(v);
		deg[v]++;
	}
	for (int j = 1; j <= N; j++) {
		if (!deg[j])  q_neightbor.push(j);
	}
	while (!q_neightbor.empty()) {
		int lesson = q_neightbor.front();
		ans += vir[lesson];
		ans %= MOD;
		q_neightbor.pop();
		for (auto k : map_neighbor[lesson]){
			deg[k]--;
			vir[k] += vir[lesson];
			vir[k] %= MOD;
			if (!deg[k]) q_neightbor.push(k);
		}
	}
	printf("%d\n", ans);
	return 0;
}