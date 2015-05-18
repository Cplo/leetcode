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

#define SIZE 1000000

int setv[SIZE];
int o;
int ql;
int qr;
int sum;
int size;
int value;

class Solution
{
public:
	void query(int o, int L, int R) {
		if (setv[o] >= 0) {
			sum += (min(R, qr) - max(L, ql) + 1)*setv[o];
		}
		else{
			int M = L + (R - L) / 2;
			if (ql <= M) query(o * 2, L, M);
			if (qr > M) query(o * 2 + 1, M + 1, R);
		}
	}
	void update(int o, int L, int R, int v) {
		int lc = o * 2, rc = o * 2 + 1;
		if (ql <= L&&R <= qr) setv[o] = v;
		else {
			if (setv[o] >= 0) {
				setv[lc] = setv[rc] = setv[o];
				setv[o] = -1;
			}
			int M = L + (R - L) / 2;
			if (ql <= M)
				update(lc, L, M, v);
			if (qr > M)
				update(rc, M + 1, R, v);
		}
	}
};

int main(void){
	Solution so;
	int N;
	scanf("%d", &N);
	int idx = ceil(log(N) / log(2));
	size = pow(2, idx);
	memset(setv, -1, 2 * size*sizeof(int));
	ql = 1;
	qr = N;
	for (int i = size; i < size + N; i++){
		scanf("%d", &setv[i]);
	}
	int Q;
	scanf("%d", &Q);
	int o, l, r;
	for (int j = 0; j < Q; j++){
		scanf("%d%d%d", &o, &l, &r);
		ql = l;
		qr = r;
		if (!o) {
			sum = 0;
			so.query(1, 1, size);
			printf("%d\n", sum);
		}
		else{
			scanf("%d", &value);
			so.update(1, 1, size, value);
		}
	}
	return 0;
}