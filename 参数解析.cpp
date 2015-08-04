#include <iostream>
#include <string>
using namespace std;

void Solution(string str)
{
	int count = 1, flag = 0;
	char para[100][100];
	for (int i = 1; i < str.size(); i++)
	{
		if (str[i] == ' ' && str[i - 1] != ' ' && flag == 0)
			count++;
		if (str[i] == '"') flag = 1;
		if (str[i] == ' ' && str[i - 1] == '"' && flag == 1)
			count++;
	}
	int i = 0, j = 0, k = 0;
	int P = count;
	while (P--)
	{
		while (str[i] != '"' && str[i] != ' ')
		{
			para[j][k++] = str[i];
			i++;
		}
		para[j][k] = '\0';

		if (str[i-1] == '"' && str[i-2] == ' ')
			while (str[i] != '"')
				para[j][k++] = str[i];
		para[j][k] = '\0';
		i++; j++;
	}

	cout << count << endl;
	for (int i = 0; i < count; i++)
	{
		int j = 0;
		while (para[i][j] != '\0')
			cout << para[i][j] ;
		cout << endl;
	}
}

void main()
{
	string str;
	getline(cin, str);
	Solution(str);
}
