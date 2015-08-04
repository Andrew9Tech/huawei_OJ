#include <iostream>
using namespace std;
int main()
{
	int y, x, start = 1;
	int n;
	cin >> n;
	for (y = 0; y < n; y++)
	{
		start += y;
		cout << start << " ";
		int end = start;
		for (x = y + 2; x <= n; x++)
		{
			end += x;
			cout << end << " ";

		}
		cout << endl;
	}
	return 0;
}
