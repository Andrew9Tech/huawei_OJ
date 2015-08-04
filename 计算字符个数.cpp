#include<iostream>
using namespace std;

int Solution(char *str, char ch)
{
	if (str == NULL || ch == NULL)	return NULL;

	int count = 0;
	while (*str != '\0')
	{
		if (*str == ch) ++count;
		++str;
	}
	return count;
}

void main()
{
	char str[1000]; char ch;
	cin.getline(str, 1000);
	cin >> ch;
	cout << Solution(str, ch);
}
