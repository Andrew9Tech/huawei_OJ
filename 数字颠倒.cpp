#include<iostream>
using namespace std;

void Solution(int num)
{
	if (num < 0)	return;

	char* str = (char*)malloc(1);
	if (num == 0)
	{
		_itoa_s(num, str, 10, 10);
		printf("%s", str);
	}
	while (num)
	{
		_itoa_s(num%10, str, 10, 10);
		printf("%s", str);
		num = num / 10;
	}

}

void main()
{
	int num;
	cin >> num;
	 Solution(num);
}
