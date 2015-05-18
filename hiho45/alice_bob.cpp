#include<stdio.h>
#include<math.h>
int sg(int k) {
	if (!k) return 0;
	if ((int)ceil(k / 2.0) % 2) {
		return k;
	}
	else{
		if (k % 2) return k + 1;
		return k - 1;
	}
}
int main(void) {
	int N;
	scanf("%d", &N);
	int ans;
	scanf("%d", &ans);
	int k;
	int i;
	ans = sg(ans);
	for (i = 1; i < N; i++){
		scanf("%d", &k);
		ans ^= sg(k);
	}
	printf("%s\n", ans ? "Alice" : "Bob");
	return 0;
}