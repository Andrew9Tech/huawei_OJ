#include<iostream>
using namespace std;

void main()
{
	char str[100];
	cin.getline(str, 100);
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] >= 'A' && str[i] < 'Z')
			cout << char(str[i] + 33);
		else if (str[i] == 'Z')
			cout << 'a';
		else if (str[i] >= 'a' && str[i] <= 'c')
			cout << '2';
		else if (str[i] >= 'd' && str[i] <= 'f')
			cout << '3';
		else if (str[i] >= 'g' && str[i] <= 'i')
			cout << '4';
		else if (str[i] >= 'j' && str[i] <= 'l')
			cout << '5';
		else if (str[i] >= 'm' && str[i] <= '0')
			cout << '6';
		else if (str[i] >= 'p' && str[i] <= 's')
			cout << '7';
		else if (str[i] >= 't' && str[i] <= 'v')
			cout << '8';
		else if (str[i] >= 'w' && str[i] <= 'z')
			cout << '9';
		else
			cout << str[i];
	}
}
