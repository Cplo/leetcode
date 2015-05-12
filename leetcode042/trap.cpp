#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<map>
#include<string.h>

//运行时间：13ms
class Solution {
public:
	int trap(vector<int>& height) {
		int i = 0, j = height.size()-1;
		int ans = 0;
		int h = 0;
		while (j-i >= 0){
			if (height[i] > height[j]){
				if (height[j] <= h){
					ans += (h - height[j]);
				}
				else{
					h = height[j];
				}
				j--;
			}
			else if (height[i] < height[j]){
				if (height[i] <= h){
					ans += (h - height[i]);
					i++;
				}
				else{
					h = height[i];
				}
			}
			else{
				if (height[i] <= h){
					if (i != j)
						ans += 2 * (h - height[i]);
					else
						ans += (h - height[i]);
				}
				else{
					h = height[i];
				}
				i++; j--;
			}
		}
		return ans;
	}
};
int main(){
	int a[100] = { 2, 0, 2 };
	vector<int> v(a, a + 3);
	Solution so;
	cout << so.trap(v) << endl;
}