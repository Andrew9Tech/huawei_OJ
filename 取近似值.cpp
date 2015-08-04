#include <iostream>
using namespace std;
int main()
{
	double a;
	cin >> a;
	if (a >= 0)
		cout << (int)(a + 0.5);
	else
		cout << (int)(a - 0.5);
}
