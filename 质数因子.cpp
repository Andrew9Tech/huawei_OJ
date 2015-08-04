#include <iostream>
using namespace std;

void getResult(long int input)
{
	for (int i = 2; i <= input; i++)
	{
		while ((input%i == 0) && input != 0)
		{
			cout << " ";
			input = input / i;
		}
	}

}

int main()
{
	int a;
	cin >> a;
	getResult(a);
	return 0;
}
