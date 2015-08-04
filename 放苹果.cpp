#include <iostream>
using namespace std;

int Solution(int m, int n)
{
	if (m == 0 || n == 1)	return 1;
	else if (m < n)	return Solution(m, m);
	else
		return Solution(m, n - 1) + Solution(m - n, n);
}

void main()
{
	int m, n;
	cin >> m;
	cin >> n;
	if ((m >= 0 && m <= 10) && (n >= 1 && n <= 10) && (n <= m))
		cout << Solution(m, n) << endl;
	else
		return;
}
