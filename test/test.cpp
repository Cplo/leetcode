#include<iostream>
#include<vector>
using namespace std;

int main(){
	vector<int> v1(5, 1);
	v1[4] = 5;
	vector<int>::iterator it;
	int k = v1.size();
	for (int i = 0; i < k;i++)
	{
		cout << v1[i] << endl;
	}
	cout << v1[v1[4]++ % 4 + 3] << endl;
	return 0;
}