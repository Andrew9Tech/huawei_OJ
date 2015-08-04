#include <iostream>
#include<iomanip>
#define E 0.0001
using namespace std;

double getCubeRoot(double num)
{
	double x0 = num;
	double result;
	while (1)
	{
		result = x0 - (x0*x0*x0 - num) / (3 * x0*x0);
		if (result*result*result - num<E && result*result*result - num>-E)
			return result;
		else
			x0 = result;
	}
}

int main()
{
	int number;
	cin >> number;
	cout << fixed << showpoint << setprecision(1) << getCubeRoot(number) << endl;
}
