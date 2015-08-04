#include<iostream>
using namespace std;

int Solution(char *str)
{
	if (str == NULL) return 0;

	int count = 0; char *p = str;
	while (*p != '\0')
	{
		++count;
		++p;
	}
	return count;
}

void main()
{
	char str[1000];
	cin.getline(str, 1000);
	cout << Solution(str);
}
