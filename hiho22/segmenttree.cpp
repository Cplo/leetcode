#include<cstdio>
using namespace std;
#include<map>
#include<string.h>
#include<queue>
#include<math.h>

#define SIZE 1000000
#define MAX_PRICE 10000
#define MIN_PRICE 1

int setv[SIZE];
int sumv[SIZE];

int o, ql, qr, ul, ur, size;

class Solution
{
public:
	void maintain(int o, int L, int R) {
		if (setv[o] > 0)
			sumv[o] = ((min(R, qr) - max(L, ql) + 1) * setv[o]);
	}
	void update0(int o, int L, int R, int v) {
		int lc = 2 * o, rc = 2 * o + 1;
		int M = L + (R - L) / 2;
		if (ul <= L&&R <= ur) {
			if (setv[o] > 0){
				int temp = setv[o] + v;
				if (temp < MIN_PRICE) temp = MIN_PRICE;
				if (temp > MAX_PRICE) temp = MAX_PRICE;
				sumv[o] = ((min(R, qr) - max(L, ql) + 1)*(temp));
				setv[o] = temp;
				return;
			}
			else {
				update0(lc, L, M, v);
				update0(rc, M + 1, R, v);
			}
		}
		else{
			if (setv[o] > 0){
				setv[lc] = setv[rc] = setv[o];
				setv[o] = -1;
			}
			if (ul <= M){
				update0(lc, L, M, v);
			}
			else{
				maintain(lc, L, M);
			}
			if (ur > M){
				update0(rc, M + 1, R, v);
			}
			else {
				maintain(rc, M+1, R);
			}
		}
		sumv[o] = sumv[lc] + sumv[rc];
	}
	void update1(int o, int L, int R, int v) {
		int lc = 2 * o, rc = 2 * o + 1;
		int M = L + (R - L) / 2;
		if (ul <= L&&R <= ur) {
			setv[o] = v;
			sumv[o] = ((min(R, qr) - max(L, ql) + 1)*(v));
			return;
		}
		else{
			if (setv[o] > 0){
				setv[lc] = setv[rc] = setv[o];
				setv[o] = -1;
			}
			if (ul <= M){
				update1(lc, L, M, v);
			}
			else{
				maintain(lc, L, M);
			}
			if (ur > M){
				update1(rc, M + 1, R, v);
			}
			else {
				maintain(rc, M + 1, R);
			}
		}
		sumv[o] = sumv[lc] + sumv[rc];
	}
};

int main(void){
	Solution so;
	int N; int Q;
	scanf("%d%d", &N, &Q);
	N++;
	int idx = ceil(log(N) / log(2));
	size = pow(2, idx);
	memset(setv, -1, 2 * size*sizeof(int));
	memset(sumv, 0, 2 * size*sizeof(int));
	int value;
	ql = 1;
	qr = N;
	for (int i = 1; i <= N; i++){
		scanf("%d", &value);
		ul = ur = i;
		so.update1(1, 1, size, value);
		//printf("%d\n", sumv[1]);
	}
	int o, l, r;
	for (int j = 0; j < Q; j++){
		scanf("%d%d%d%d", &o, &l, &r, &value);
		ul = l + 1;
		ur = r + 1;
		if (!o) {
			so.update0(1, 1, size, value);
		}
		else{
			so.update1(1, 1, size, value);
		}
		//so.query(1, 1, size);
		printf("%d\n", sumv[1]);
	}
	return 0;
}