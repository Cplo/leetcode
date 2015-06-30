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
const int N = 16385;
vector<vector<int>> matrix;
int n;
vector<int> path;
void dfs(int u, int& size){
	while (!matrix[u].empty()) {
		int x = matrix[u].back();
		matrix[u].pop_back();
		dfs(x,size);
	}
	path.push_back(u);
}
int main(void) {
	scanf("%d", &n);
	if (n == 1) printf("01\n");
	else if (n == 2) printf("0011\n");
	else {
		int row = pow(2, n - 1);
		for (int i = 0; i < row; i++){
			vector<int> v;
			int k = i; if (k >= (1 << (n - 2))) k -= 1 << (n - 2);
			for (int j = 0; j < row; j++) if (j >> 1 == k) v.push_back(j);
			matrix.push_back(v);
		}
		dfs(0, row);
		char ans[32769];
		int head = 0;
		for (int i = path.size() - 1; i >= 1; i--){
			ans[head++] = (path[i] & 1) + '0';
		}
		ans[head] = '\0';
		printf("%s\n", ans);
	}
	return 0;
}