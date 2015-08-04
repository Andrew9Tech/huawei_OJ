#include <iostream>
using namespace std;


int main()
{
	int n, stature[100], result = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> stature[i];
	stature[n] = '\0';

	int *listrise = new int[n];       //上升子序列

	for (int i = 0; i < n; i++)
	{
		listrise[i] = 1;
		for (int j = 0; j < i; j++)
			if ((stature[i] > stature[j]) && (listrise[j] + 1 > listrise[i]))
				listrise[i] = listrise[j] + 1;
	}

	int *listdown = new int[n];
	for (int i = n - 1; i >= 0; i--)
	{
		listdown[i] = 1;
		for (int j = n - 1; j > i; j--)
			if ((stature[i] > stature[j]) && (listdown[j] + 1> listdown[i]))
				listdown[i] = listdown[j] + 1;
	}

	for (int i = 0; i < n; i++)
		if (listrise[i] + listdown[i] - 1> result)
			result = listrise[i] + listdown[i] - 1;
	cout << n - result << endl;
}
