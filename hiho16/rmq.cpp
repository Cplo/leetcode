#include<cstdio>
#include<string>
#include<string.h>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#define SIZE 1000005
using namespace std;
int arr[SIZE];
int calc[SIZE][20];
int n, q;
void RMQ_init(void){
	int index = floor(log(n) / log(2));
	for (int j = 1; j <= index; j++) {
		for (int i = 1; i+(1<<j)-1<=n; i++){
			calc[i][j] = min(calc[i][j-1],calc[i+(1<<(j-1))][j-1]);
		}
	}
}
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		scanf("%d", arr + i);
		calc[i][0] = arr[i];
	}
	RMQ_init();
	scanf("%d", &q);
	int l, r;
	for (int i = 0; i < q; i++){
		scanf("%d%d", &l, &r);
		int j = floor(log(r - l + 1) / log(2));
		int rr = r - (1<<j) + 1;
		printf("%d\n", min(calc[l][j], calc[rr][j]));
	}
	return 0;
}

//Ïß¶ÎÊ÷´úÂë
//#include<cstdio>
//using namespace std;
//#include<vector>
//#include<algorithm>
//#include<map>
//#include<string.h>
//#include<string>
//#include<queue>
//#include<float.h>
//#include<math.h>
//
//#define SIZE 3000000
//#define INF 10000
//int minv[SIZE];
//int o;
//int ql;
//int qr;
//int sum;
//int size;
//int value;
//
//class Solution
//{
//public:
//	Solution();
//	int query(int o, int L, int R) {
//		if (ql <= L&&R <= qr) return minv[o];
//		int M = L + (R - L) / 2;
//		int ans = INF;
//		if (ql <= M) ans = query(o * 2, L, M);
//		if (qr > M) ans = min(ans, query(o * 2 + 1, M + 1, R));
//		return ans;
//	}
//	void update(int o, int L, int R, int v) {
//		if (L == R) minv[o] = v;
//		else{
//			int M = L + (R - L) / 2;
//			int lc = o * 2, rc = o * 2 + 1;
//			if (ql <= M)
//				update(lc, L, M, v);
//			else
//				update(rc, M + 1, R, v);
//			minv[o] = min(minv[lc], minv[rc]);
//		}
//	}
//	~Solution();
//
//private:
//
//};
//
//Solution::Solution()
//{
//}
//
//Solution::~Solution()
//{
//}
//
//int main(void){
//	Solution so;
//	int N;
//	scanf("%d", &N);
//	int idx = ceil(log(N) / log(2));
//	size = pow(2, idx);
//	memset(minv, INF, 2 * size*sizeof(int));
//	int temp;
//	for (int i = size; i < size + N; i++){
//		scanf("%d", &temp);
//		ql = qr = i - size + 1;
//		so.update(1, 1, size, temp);
//	}
//	int Q;
//	scanf("%d", &Q);
//	int l, r;
//	for (int j = 0; j < Q; j++){
//		scanf("%d%d", &l, &r);
//		ql = l;
//		qr = r;
//		printf("%d\n", so.query(1, 1, size));
//	}
//	return 0;
//}