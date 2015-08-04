#include<iostream>
using namespace std;

int Solution(int n)
{
	if (n <= 2) return 1;
	else
		return Solution(n - 1) + Solution(n - 2);
}

void main()
{
	int n;
	cin >> n;
	cout << Solution(n) << endl;
}
