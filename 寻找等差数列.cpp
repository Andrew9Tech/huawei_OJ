#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
bool Isprime(int n)
{
	int flag = 1;
	if (n<2)
		return false;
	if (n == 2)
		return true;
	for (int i = 2; i <= sqrt((double)n); i++)
		if (n%i == 0)
		{
		flag = 0;
		break;
		}
	if (flag)
		return true;
	else
		return false;
}

bool find(int m, int a[], int n)
{
	int flag = 0;
	for (int i = 0; i<n; i++)
		if (m == a[i])
			flag = 1;
	if (flag)
		return true;
	else
		return false;
}

int main()
{
	int min, max, a[1000], k = 0, len = 1, end, dk = 0;
	vector<int> d;
	cin >> min >> max;
	for (int i = min; i <= max; i++)
		if (Isprime(i))
			a[k++] = i;   //所有的素数存起来
	for (int i = 0; i<k; i++)
		for (int j = i + 1; j<k; j++)
			d.push_back(a[j] - a[i]);
	sort(d.begin(), d.end());
	vector<int>::iterator it = unique(d.begin(), d.end());
	d.erase(it, d.end());  //所有的不重复的公差存起来

	for (int i = 0; i<k; i++)
		for (int j = 0; j<d.size(); j++)
		{
		int tmp = d[j], count = 1;
		while (find((a[i] + tmp), a, k))
		{
			count++;
			tmp += d[j];
		}

		if (count>len || (count == len &&d[j]>dk))
		{
			len = count;
			end = a[i];
			dk = d[j];

		}
		count = 1;
		}

	for (int i = 0; i<len; i++)
	{
		cout << end;
		//if(i==len-1)
		cout << endl;
		//else
		//cout<<" ";
		end += dk;
	}
	return 0;
}
