#include<iostream>
using namespace std;

int main()
{
	int a[100][100], b[100][100], c[100][100] = { 0 };
	int x, y, z;
	cin >> x;
	cin >> y;
	cin >> z;
	for (int i = 0; i<x; i++)
		for (int j = 0; j<y; j++)
			cin >> a[i][j];
	for (int i = 0; i<y; i++)
		for (int j = 0; j<z; j++)
			cin >> b[i][j];

	for (int i = 0; i < x; i++)
		for (int j = 0; j < z; j++)
			for (int k = 0; k < y; k++)
				c[i][j] = a[i][k] * b[k][j];

	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < z - 1; j++)
			cout << c[i][j] << " ";
		cout << c[i][z - 1] << endl;
	}
	return 0;
}
