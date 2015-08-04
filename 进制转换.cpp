#include<iostream>
using namespace std;

char* Solution(char *str)
{
	if (str == NULL || *str != '0' || *(++str) != 'x') 
		return NULL;
	if (strlen(str) < 3) 
		return NULL;
	int num = 0; int temp = 0;
	++str; 
	while (*str != '\0')
	{
		if (!((0 < (*str - '0') && (*str - '0') < 10) || (0 < (*str - 'a') && (*str - 'a') < 5) || (0 < (*str - 'A') && (*str - 'A') < 5)))
			break;
		if (0 < (*str - '0') && (*str - '0') < 10)
			temp = (*str - '0');
		if (0 < (*str - 'a') && (*str - 'a') < 5)
			temp = (*str - 'a') + 10;
		if (0 < (*str - 'A') && (*str - 'A') < 5)
			temp = (*str - 'A') + 10;
		num = num * 16 + temp;	
		++str;
	}
	char* str0 = (char*)malloc(33);
	_itoa_s(num, str0, 10, 10);
	return str0;
}

void main()
{
	char str[1000];
	cin >> str;
	cout << Solution(str) << endl;
}
