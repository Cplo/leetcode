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


int arr[1000000];
class Solution {
public:
	void grayCode(vector<int> &ans, string s, int num){
		arr[num] = 1;
		ans.push_back(num);
		if (ans.size() == size) return;
		int temp = num;
		for (int i = n-1; i >= 0; i--){
			num = temp;
			if (s[i] - '0')  {
				num -= pow(2, n - 1 - i);
				if (!arr[num]) {
					s[i] = '0';
					grayCode(ans, s, num);
					return;
				}
			}
			else {
				num += pow(2, n - 1 - i);
				if (!arr[num]){
					s[i] = '1';
					grayCode(ans, s, num);
					return;
				}
			}
		}
	}
	vector<int> grayCode(int n) {
		vector<int> ans;
		/*if (!n) {
			ans.push_back(0);
			return ans;
		}*/
		this->n = n;
		this->size = (int)pow(2, n);
		string s(n ,'0');
		memset(arr, 0, size*sizeof(int));
		grayCode(ans, s, 0);
		return ans;
	}
private:
	int n;
	int size;
};

int main(void)	{
	Solution so;
	so.grayCode(2);
	return 0;
}