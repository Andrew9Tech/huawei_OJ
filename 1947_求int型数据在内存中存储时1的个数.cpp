#include<iostream>
using namespace std;

int Solution(int num)
{
	int count = 0;
	while (num)
	{
		++count;
		num = num & (num - 1);
	}
	return count;
}

void main()
{
	int num;
	cin >> num;
	cout << Solution(num);
}
