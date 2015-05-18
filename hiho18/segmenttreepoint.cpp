//18ms
#include<cstdio>
using namespace std;
#include<vector>
#include<algorithm>
#include<map>
#include<string.h>
#include<string>
#include<queue>
#include<float.h>
#include<math.h>

#define SIZE 3000000
#define INF 10000
int minv[SIZE];
int o;
int ql;
int qr;
int sum;
int size;
int value;

class Solution
{
public:
	int query(int o, int L, int R) {
		if (ql <= L&&R <= qr) return minv[o];
		int M = L + (R - L) / 2;
		int ans = INF;
		if (ql <= M) ans =  query(o * 2, L, M);
		if (qr > M) ans = min(ans, query(o * 2 + 1, M + 1, R));
		return ans;
	}
	void update(int o, int L, int R, int v) {
		if (L == R) minv[o] = v;
		else{
			int M = L + (R - L) / 2;
			int lc = o * 2, rc = o * 2 + 1;
			if (ql<=M)
				update(lc, L, M, v);
			else
				update(rc, M + 1, R, v);
			minv[o] = min(minv[lc], minv[rc]);
		}
	}
};

int main(void){
	Solution so;
	int N;
	scanf("%d", &N);
	int idx = ceil(log(N) / log(2));
	size = pow(2, idx);
	memset(minv, INF, 2 * size*sizeof(int));
	ql = 1;
	qr = N;
	int temp;
	for (int i = size; i < size + N; i++){
		scanf("%d", &temp);
		ql = i - size + 1;
		so.update(1, 1, size, temp);
	}
	int Q;
	scanf("%d", &Q);
	int o, l, r;
	for (int j = 0; j < Q; j++){
		scanf("%d%d%d", &o, &l, &r);
		if (!o) {
			ql = l;
			qr = r;
			printf("%d\n", so.query(1, 1, size));
		}
		else{
			ql = qr = l;
			value = r;
			so.update(1, 1, size, value);
		}
	}
	return 0;
}