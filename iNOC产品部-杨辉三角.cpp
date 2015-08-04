#include <iostream>
using namespace std;
void main()
{
	int n;
	cin >> n;
	if (n % 2 == 1)	cout << 2 << endl;
	else if (n % 2 == 0 && (n / 2 % 2 + 3 <= n + 1))
		cout << n / 2 % 2 + 3 << endl;
	else
		cout << -1 << endl;
}
