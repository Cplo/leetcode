#include<cstdio>
#include<vector>
#include<string>
#include<string.h>
#include<algorithm>
#include<map>
#include<float.h>
#include<stack>
#include<math.h>
#include<queue>
using namespace std;
const int N = 1001;
int deg[N];
int matrix[N][N];
int n, m, u, v;
vector<int> path;
void dfs(int u){
	for (int i = 1; i <= n; i++){
		if (matrix[u][i]) {
			--matrix[u][i]; --matrix[i][u];
			dfs(i);
		}
	}
	path.push_back(u);
}
int main(void) {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++){
		memset(matrix[i], 0, N*sizeof(int));
	}
	for (int i = 0; i < m; i++){
		scanf("%d%d", &u, &v);
		matrix[u][v]++; matrix[v][u]++;
		deg[u]++; deg[v]++;
	}
	int flag = 0;
	for (int i = 1; i <= n; i++){
		if (deg[i] % 2) {
			dfs(i); flag = 1; break;
		}
	}
	if (!flag) dfs(1);
	for (auto k : path) printf("%d ", k);
	printf("\n");
	return 0;
}