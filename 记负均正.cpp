#include <iostream>
#include<iomanip>
using namespace std;
int main()
{
	int a[100];
	int n;
	int countfu = 0;
	int count = 0;
	int sum = 0;
	double average = 0;
	cin >> n;
	for (int i = 0; i<n; i++)
	{
		int m;
		cin >> m;
		a[i] = m;
	}
	for (int i = 0; i<n; i++)
	{
		if (a[i]<0)
			countfu++;
		else if (a[i]>=0)
		{
			sum += a[i];
			count++;
		}
	}
	average = double(sum) / count;
	cout << countfu;
	cout << ' ';
	if (sum % (count) == 0)
		cout << sum / (count) << endl;
	else
		cout << fixed << setprecision(1) << average << endl;
}
