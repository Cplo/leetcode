#include<iostream>
#include<algorithm>
using namespace std;

#include <vector>
#pragma warning(disable:4996)
class Solution {
public:
	vector<int> twoSum(vector<int> &numbers, int target) {
		vector<int> oput;
		vector<int> vec;
		for (int m = 0; m < numbers.size(); m++)
		{
			vec.push_back(numbers[m]);
		}
		sort(numbers.begin(), numbers.end());
		int i = 0;
		int j = numbers.size() - 1;
		int sum;
		do
		{
			sum = numbers[i] + numbers[j];
			if (target == sum)
				break;
			else if (target > sum)
				i++;
			else
				j--;
		} while (true);
		for (int m = 0;m < vec.size(); m++)
		{
			if (vec[m] == numbers[i] || vec[m] == numbers[j])
				oput.push_back(m + 1);
			if (oput.size() == 2)
				break;
		}
		return oput;
	}
};
int main()
{
	Solution so;
	vector<int> *iput = new vector<int>();
	int n,k;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> k;
		iput->push_back(k);
	}
	int target;
	cin >> target;
	vector<int> v = so.twoSum(*iput, target);
	system("pause");
	return 0;
}