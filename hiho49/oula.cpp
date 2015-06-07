#include<cstdio>
#include<string.h>
const int MAX = 10005;
int rep[MAX];
int deg[MAX];
int find(int x) {
	if (x == rep[x]) return x;
	rep[x] = find(rep[x]);
	return rep[x];
}
void join(int x, int y){
	int fx = find(x);
	int fy = find(y);
	if (fx != fy) rep[fx] = fy;
}
int main(void) {
	int N, M, u, v, count = 0, isFull = 1;
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++) rep[i] = i;
	memset(deg, 0, (N + 1)*sizeof(int));
	for (int i = 0; i < M; i++) { scanf("%d%d", &u, &v); join(u, v); deg[u]++; deg[v]++; }
	for (int i = 1; i <= N; i++){
		if (deg[i] % 2) { count++; if (count > 2) { isFull = 0; break; } }
		if (i != 1 && (find(i) != find(1))) { isFull = 0; break; }
	}
	isFull ? printf("Full\n") : printf("Part\n");
	return 0;
}