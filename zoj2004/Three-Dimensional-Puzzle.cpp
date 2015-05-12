#include<cstdio>
#include<string.h>
//using namespace std;

#define N 1000007
int a[N];
int b[N];
long long inv;
//
void merge(int first, int mid, int last)
{
	int i, j, k;
	memcpy(b + first, a + first, (last - first + 1)*sizeof(int));
	k = i = first, j = mid + 1;
	while (i <= mid || j <= last)
	{
		if (j > last || (i <= mid&&b[j] >= b[i]))
		{
			a[k++] = b[i++];
			inv += (j - (mid + 1));
		}
		else
		{
			a[k++] = b[j++];
			//inv += ((mid + 1) - i) & 1;
		}
	}
}

void msort(int first,int last)
{
	if (first>=last)
		return;
	int mid = (first + last) / 2;
	msort(first, mid);
	msort(mid + 1, last);
	merge(first, mid, last);
}

int main()
{
	int m, n, s, j, iter, v, y = 0;
	while (scanf("%d%d", &m,&n)==2)
	{
		if (!m || !n)
			break;
		s = m * n;
		for (iter = j = 0; j < s; j++)
		{
			scanf("%d", &v);
			v ? (a[iter++] = v) : ( y = m - 1 - j / n);
		}
		inv = 0;
		msort(0, iter - 1);
		//cout << inv << endl;
		//若列数为奇数，则数字的上下左右移动都不影响最终逆序对的总数
		if (n & 1)
		{
			y = 0;
		}
		printf(((y % 2 == inv % 2) ? "YES\n" : "NO\n"));
	}
	//system("pause");
}