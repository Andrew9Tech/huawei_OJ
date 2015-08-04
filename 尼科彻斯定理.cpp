#include <iostream>
using namespace std;

void Solution(int n)
{
	int x;
	x = n * n - n + 1;

	for (int i = 0; i < n - 1; i++)
			cout << x + 2 * i << "+";	
	cout << x + 2 * (n-1) << endl;
}

int main()
{
	int num;
	cin >> num;
	if (num <= 100)
		Solution(num);
	else
		return -1;
	return 0;
}
