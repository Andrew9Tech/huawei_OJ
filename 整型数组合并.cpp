#include<iostream>
#include<algorithm>
using namespace std;

bool compare(const int &a, const int &b)
{
	return a<b;
}

void Solution(int a[], int lenA, int b[], int lenB, int c[])
{

	sort(a, a + lenA, compare);   //两个数组从小到大排序
	sort(b, b + lenB, compare);

	for (int i = 0; i<lenA; ++i)  //去除a中重复的数
	{
		if (a[i] == a[i + 1])
		{
			for (int j = i + 1; j<lenA; j++)
				a[j] = a[j + 1];
			lenA--;
			--i;
		}
	}


	for (int i = 0; i<lenB; ++i)  //去除b中重复的数
	{
		if (b[i] == b[i + 1])
		{
			for (int j = i + 1; j<lenB; j++)
				b[j] = b[j + 1];
			lenB--;
			--i;
		}
	}
	int p = 0, q = 0, k = 0;
	while (p < lenA && q < lenB)
	{
		if (a[p] < b[q])
		{
			c[k] = a[p];
			k++; p++;
		}
		else if (a[p] == b[q])
		{
			c[k] = a[p];
			k++; p++; q++;
		}
		else if (a[p] > b[q])
		{
			c[k] = b[q];
			k++; q++;
		}
	}
	if (p < lenA)
	{
		for (int i = p; i < lenA; i++)
		{
			c[k] = a[i];
			k++;
		}
	}
	if (q < lenB)
	{
		for (int i = q; i < lenB; i++)
		{
			c[k] = b[i];
			k++;
		}
	}

	for (int i = 0; i<k; i++)
		cout << c[i];
}


int main()
{
	int a[100], b[100], c[200], m, n;
	cin >> m;     //第一个数组的个数
	for (int i = 0; i < m; i++)
	{
		int number;
		cin >> number;
		a[i] = number;
	}
	cin >> n;     //第二个数组的个数
	for (int i = 0; i < n; i++)
	{
		int number;
		cin >> number;
		b[i] = number;
	}
	
	Solution(a, m, b, n, c);
}
