#include<iostream>
#include<vector>
#include<string>
#include<string.h>
#include<algorithm>
#include<map>
#include<float.h>
#include<stack>
#include<math.h>
#include<queue>
#include<unordered_set>
using namespace std;

class Solution {
public:
	//横坐标A,C E,G 纵坐标B,D F,H
	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
		int area1 = abs(A - C)*abs(B - D);
		int area2 = abs(E - G)*abs(F - H);
		//无交集——返回两者之和
		if (min(E, G) >= max(A, C) || max(E, G) <= min(A, C) || min(F, H) >= max(B, D) || max(F, H) <= min(B, D)) return area1 + area2;
		//包含关系——返回最大的
		if (E >= A&&F >= B&&G <= C&&H <= D || E <= A&&F <= B&&G >= C&&H >= D) return max(area1, area2);
		//有交集——两者之和-交集面积
		int ans = 0;
		if (A <= E) {
			ans += (E - A)*(D - B);
			if (G < C) {
				ans += (G - E) * (max(D, H) - min(F, B));
				ans += (C - G) * (D - B);
			}
			else {
				ans += (C - E) * (max(D, H) - min(F, B));
				ans += (G - C)*(H - F);
			}
		}
		else {
			ans += (A - E) * (H - F);
			if (C < G) {
				ans += (C - A)*(max(D, H) - min(F, B));
				ans += (G - C) * (H - F);
			}
			else {
				ans += (G - A)*(max(D, H) - min(F, B));
				ans += (C - G) * (D - B);
			}
		}
		return ans;
	}
};

int main(void){
	Solution so;
	cout<<so.computeArea(-3, 0, 3, 4, 0, -1, 9, 2);
	return 0;
}