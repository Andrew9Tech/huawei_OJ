#include<iostream>
using namespace std;

int Solution(char *str)
{
	if (str == NULL) return NULL;

	int count = 0;
	while (*str != '\0')
	{
		if (*str >= 'A' && *str <= 'Z')	++count;
		++str;
	}
	return count;
}

void main()
{
	char string[100];
	cin.getline(string, 100);
	cout << Solution(string) << endl;
}
