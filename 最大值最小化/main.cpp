#include<iostream>
using namespace std;

#define N 1000000
int a[N];

int search_min(int n,int k)
{
	int sum=0;
	for (int i = 0; i < n; i++)	sum += a[i];
	int x = a[0], y = sum;
	while (1)
	{
		int s = 0, sum = a[0], i;
		int mid = x + (y - x) / 2,max,flag = 0;
		for (i = 1; i < n; i++)
		{
			if (sum <= mid&&sum + a[i] > mid)	
			{
				if (!flag){ flag = 1; max = sum; }
				if (sum>max) max = sum;
				sum = a[i]; s++;
			}
			else                               
			{ sum += a[i]; }
		}
		if (s <= k - 1)	
		{
			if (sum > max) max = sum; 
			y = max;//ͨ��y����ȡ���Ż��⡣
		}
		else if(x!=mid)       x = mid ;
		else break;//������ִ���𰸲��Һ���ֵ��ͬ���˳����ҡ�
	}
	return y;
}

int main()
{
	int n,k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)	cin >> a[i];
	cout << search_min(n,k) << endl;
	//system("pause");
	return 0;
}