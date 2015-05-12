#include<iostream>
using namespace std;

int main()
{
	int i, b;
	double a, c, x=0, y=100;
	cin >> a >> b >> c;
	while (y - x > 1e-5)
	{
		double m = x + (y - x) / 2;
		double f = a;
		for (i = 0; i < b; i++) f += (f*m / 100.0 - c);
		if (f>0) y = m;
		else
		{
			x = m;
		}
	}
	printf("%.3lf%%\n", x);
	system("pause");
	return 0;
}