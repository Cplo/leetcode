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
	int countPrimes(int n) {
		if (n <= 2) return 0;
		int *arr = new int[n];
		memset(arr, -1, n*sizeof(n));
		/*vector<int> v;
		v.push_back(2);
		for (int i = 3; i < n; i+=2) {
			int j = 0;
			int size = v.size();
			int isprime = true;
			for (; j < size && v[j] <= sqrt(i); j++) {
				if (i%v[j] == 0) {
					isprime = false; break;
				}
			}
			if (isprime) v.push_back(i);
		}
		return v.size();*/
		arr[2] = 1;
		int ans = 1;
		for (int i = 3; i < n; i+=2){
			if (arr[i] == -1) {
				ans++;
				arr[i] = 1;
				for (int j = 2 * i; j < n; j += i) {
					arr[j] = 0;
				}
			}
		}
		return ans;
	}
	string convertToTitle(int n) {
		string ans = "";
		if (n<1) return ans;
		int idx = 0;
		int sum = 0;
		char ch;
		while (sum + pow(26, idx) <= n) {
			sum += pow(26, idx);
			idx++;
		}
		for (int i = idx - 1; i >= 1; i--){
			int x = n / pow(26, i);
			if (n % (int)pow(26, i) == 0) x--;
			ch = x  - 1 + 'A';
			ans += ch;
			n -= x * pow(26, i);
		}
		ch = n - 1 + 'A';
		ans += ch;
		return ans;
	}
};

int main(void) {
	Solution so;
	//cout << so.countPrimes(1500000) << endl;
	cout << so.convertToTitle(702) << endl;
	cout << so.convertToTitle(703) << endl;
	cout << so.convertToTitle(27) << endl;
	cout << so.convertToTitle(26) << endl;
	cout << so.convertToTitle(52) << endl;
	cout << so.convertToTitle(53) << endl;
	//for (int i = 26; i <= 1000;i+=26)
	//cout << so.convertToTitle(i) << endl;
	return 0;
}