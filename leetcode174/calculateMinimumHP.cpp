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
#include<unordered_set>
using namespace std;

class Solution {
public:
	int calculateMinimumHP(vector<vector<int>>& dungeon) {
		int arr[1000][1000];
		int n = dungeon.size();
		int m = dungeon[0].size();
		for (int i = n - 1; i >= 0; i--) {
			for (int j = m - 1; j >= 0; j--) {
				if (i == n - 1) {
					if (j == m - 1){
						arr[i][j] = 1 - dungeon[i][j];
						if (arr[i][j] < 1)  arr[i][j] = 1;
					}
					else {
						arr[i][j] = arr[i][j + 1] - dungeon[i][j];
						if (arr[i][j] < 1)  arr[i][j] = 1;
					}
					continue;
				}
				if (j == m - 1) {
					arr[i][j] = arr[i + 1][j] - dungeon[i][j];
					if (arr[i][j] < 1)  arr[i][j] = 1;
					continue;
				}
				arr[i][j] = min(arr[i + 1][j], arr[i][j + 1]) - dungeon[i][j];
				if (arr[i][j] < 1)  arr[i][j] = 1;
			}
		}
		return arr[0][0];
	}
};

int main(void) {
	int a[3][3] = { {-2,-3,3}, {-5,-10,1}, {10,30,-5} };
	vector<vector<int>> v;
	for (int i = 0; i < 3; i++){
		vector<int> v1(a[i], a[i] + 3);
		v.push_back(v1);
	}
	Solution so;
	printf("%d\n", so.calculateMinimumHP(v));
	return 0;
}