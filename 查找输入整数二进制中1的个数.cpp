#include<iostream>
using namespace std;

int Solution(int num)
{
	int count = 0;
	while (num)
	{
		num = num & (num - 1);
		count++;
	}
	return count;
}

void main()
{
	int num;
	cin >> num;
	cout << Solution(num) << endl;
}
