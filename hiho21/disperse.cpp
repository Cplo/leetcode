#include<cstdio>
using namespace std;
#include<vector>
#include<string.h>
#include<algorithm>
#include<map>
#include<math.h>
#define SIZE 1000000
#define NUM 100005

int setv[SIZE];
int ql;
int qr;
map<int,int> ans;
int MAX;

class Solution
{
public:
	void query(int o, int L, int R) {
		if (setv[o] > 0&&(R-L)) {
			ans[setv[o]]++;
		}
		else{
			int M = L + (R - L) / 2;
			int lc = o * 2, rc = o * 2 + 1;
			if (ql < M && (M - L) && lc <= MAX) query(lc, L, M);
			if (qr > M && (R - M) && rc <= MAX) query(rc, M, R);
		}
	}
	void update(int o, int L, int R, int v) {
		int lc = o * 2, rc = o * 2 + 1;
		if (ql <= L&&R <= qr) setv[o] = v;
		else {
			if (setv[o] > 0) {
				setv[lc] = setv[rc] = setv[o];
				setv[o] = -1;
			}
			int M = L + (R - L) / 2;
			if (ql < M)
				update(lc, L, M, v);
			if (qr > M)
				update(rc, M , R, v);
		}
	}
};
struct post
{
	int l;
	int r;
}posts[NUM];

int main(void){
	Solution so;
	//数据做预处理
	int N, L;
	scanf("%d%d", &N, &L);
	vector<int> v;
	for (int i = 0; i < N; i++) {
		scanf("%d%d", &(posts[i].l), &(posts[i].r));
		v.push_back(posts[i].l);
		v.push_back(posts[i].r);
	}
	sort(v.begin(), v.end());
	map<int, int> m;
	int j = 1;
	int pre;
	int n = v.size();
	for (int i = 0; i < n; ){
		m[v[i]] = j;
		pre = v[i];
		i++;
		while (i < n &&v[i] == pre) i++;
		j++;
	}
	int idx = ceil(log(m.size() - 1) / log(2));
	int size = pow(2, idx);
	MAX = 2 * size - 1;
	memset(setv, -1, 2 * size *sizeof(int));
	
	for (int i = 0; i < N; i++) {
		ql = m[posts[i].l];
		qr = m[posts[i].r];
		so.update(1, 1, 1+size, i + 1);
	}
	ql = 1;
	qr = m.size();
	so.query(1, 1, 1+size);
	printf("%d\n", ans.size());
	return 0;
}