#include<iostream>
using namespace std;

#define N 1000000
int a[N];

//选取枢纽元（3种方法）
//1:选左端
//int select_pivot(int p, int q)
//{
//	return a[p];
//}
//2:取中数
//void swap_ab(int p, int q)
//{
//	int temp = a[p];
//	a[p] = a[q];
//	a[q] = temp;
//}
//int select_pivot(int p, int q)
//{
//	int m = (p + q) / 2;
//	//m p q;
//	if (a[m] > a[q])
//	{
//		swap_ab(m, q);
//	}
//	if (a[p] > a[q])
//	{
//		swap_ab(p, q);
//	}
//	if (a[m] > a[p])
//	{
//		swap_ab(m, p);
//	}
//	return a[p];
//}

//随机枢纽元
void swap_ab(int p, int q)
{
	int temp = a[p];
	a[p] = a[q];
	a[q] = temp;
}
int select_pivot(int p, int q)
{
	int i = p + rand() % (q-p+1);
	swap_ab(i, p);
	return a[p];
}

//双向扫描
//int partition(int p, int q)
//{
//	int pivot = select_pivot(p, q);
//	/*int i = p + 1, j = q;
//	int t = p;
//	while (i <= j)
//	{
//		while (j >= i)
//		{
//			if (pivot <= a[j])
//				j--;
//			else
//			{
//				a[t] = a[j];
//				t = j;
//				j--;
//				break;
//			}
//		}
//		while (i <= j)
//		{
//			if (pivot >= a[i])
//				i++;
//			else
//			{
//				a[t] = a[i];
//				t = i;
//				i++;
//				break;
//			}
//		}
//	}
//	a[t] = pivot;
//	return t;*/
//	int i = p,j=q+1;
//	while (1)
//	{
//		do i++; while (i <= q&&a[i] <= pivot);
//		do j--; while (j >= p+1&&a[j] >= pivot);
//		if (i > j) break;
//		swap_ab(i, j);
//	}
//	swap_ab(j, p);
//	return j;
//}
////单向扫描
int partition(int p, int q)
{
	int pivot = select_pivot(p, q);
	int i = p;
	for (int j = p + 1; j <= q; j++)
	{
		if (a[j] <= pivot)
		{
			i++;
			swap_ab(j, i);
		}
	}
	swap_ab(i, p);
	return i;
}

void quicksort(int p,int q)
{
	if (p >= q)	return;
	int t = partition(p, q);
	quicksort(p, t - 1);
	quicksort(t + 1, q);
}

int search(int p,int q,int k)
{
	if (p >= q)	return -1;
	int t = partition(p, q);
	if (t + 1 == k)
		return a[t];
	else if (t + 1 > k)
		return search(p, t,k);
	else
		return search(t + 1, q, k);
}

int main()
{
	int n,k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cout << search(0,n-1,3) << endl;
	quicksort(0, n-1);
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl;
	system("pause");
	return 0;
}