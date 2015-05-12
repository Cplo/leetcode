#include<iostream>

using namespace std;
#define N 100005

int a[N];
int rear;

void ins()
{
	int i = rear, j = i/2;
	int temp = a[rear];
	while (j>=1 && temp > a[j])
	{
		//cout << "test" << endl;
		a[i] = a[j];
		i = j;
		j = j / 2;
	}
	a[i] = temp;
}

void del()
{
	if (rear < 1)
		return;
	int temp = a[1] = a[rear];
	rear--;
	int i = 1,j=2*i,big=i;
	while (j <= rear)
	{
		//cout << "test" << endl;
		big = j;
		if (j + 1 <= rear && a[j] < a[j + 1])
			big = j + 1;
		if (temp < a[big])
		{
			a[i] = a[big];
			i = big;
			j = i*2;
		}
		else
		{
			break;
		}
	}
	a[i] = temp;
}

void deal(int n)
{
	int w;
	char e;
	for (int i = 0; i < n; i++)
	{
		cin >> e;
		if (e == 'A')
		{
			rear++;
			cin >> a[rear];
			ins();
		}
		else
		{
			cout << a[1] << endl;
			del();
		}
	}
}

int main()
{
	int n;
	cin >> n;
	rear = 0;
	deal(n);
	return 0;
}