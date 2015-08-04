#include<iostream>
using namespace std;

void Solution(char *str)
{
	if (str == NULL) return;

	char *p1 = str; char *p2 = str;
	while (*p2 != '\0')	++p2;
	--p2;
	while (p1 < p2)
	{
		char temp = *p1;
		*p1 = *p2;
		*p2 = temp;
		++p1; --p2;
	}
}

void main()
{
	char str[100];
	cin.getline(str, 100);
	Solution(str);
	cout << str;
}
