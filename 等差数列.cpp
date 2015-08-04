#include<iostream>
using namespace std;

int Solution(int num)
{
	if (num < 0) return NULL;
	return ((3 * num + 1)* num)/2;
}

void main()
{
	int num;
	cin >> num;
	cout << Solution(num) << endl;
}
