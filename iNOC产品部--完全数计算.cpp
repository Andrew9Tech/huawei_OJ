#include<iostream>
using namespace std;

int Solution(int n)
{
	int count = 0;
	for (int i = 1; i < n; i++)
	{
		int sum = 0;
		for (int j = 1; j < i; j++)
		{
			if (i%j == 0) sum += j;
		}
		if (sum == i)
			count++;
	}
	return count;
}

int main()
{
	int num;
	cin >> num;
	if (num > 0)
	{
		cout << Solution(num) << endl;
		return 0;
	}
	else
		return -1;
}
