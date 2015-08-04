#include<iostream>
#include <string>
using namespace std;

void main()
{
	string str;
	cin >> str;
	int count[26] = {0};

	for (int i = 0; i < str.size(); i++)
		count[str[i] - 97] += 1;
	for (int i = 0; i < str.size(); i++)
	{
		for (int j = 0; j < 26; j++)
		{
			if ((count[str[i] - 97] > count[j]) && count[j] != 0)
			{
				cout << str[i];
				break;
			}
		}
	}
	cout << endl;
}
