#include<iostream>
using namespace std;

void main()
{
	double heigh, s = 0.0;
	cin >> heigh;
	s = heigh;
	for (int i = 1; i < 5; i++)
	{
		heigh = 0.5 * heigh;
		s += heigh * 2;
	}
	cout << s  << endl;
	cout << heigh * 0.5 << endl;
}
