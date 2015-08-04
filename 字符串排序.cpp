#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;

int main()
{
	string str;
	getline(cin, str);

	int Len = str.size();
	for (int i = 1; i < Len; i++)
	{
		for (int j = Len - 1; j >= i; j--)
		{
			int k = j - 1;
			if (isalpha(str[j]))
			{
				while (!isalpha(str[k]))	--k;
				if (tolower(str[k]) > tolower(str[j]))
				{
					int temp = str[j];
					str[j] = str[k];
					str[k] = temp;
				}
			}
			else
				continue;
		}
	}
	
	cout << str << endl;
}
