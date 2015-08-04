#include<iostream>
using namespace std;


void Solution(char* str)
{
	if (str == NULL) return;
	int count = 0, i = 0;
	char *p = str;
	for (int i = 0; i < strlen(str); i++)
		if (str[i] == '.' && str[i + 1] != '.')
			count++;

	char *p2 = str;
	if (count == 3)
	{
		int k = 0, temp = 0, flag = 0;
		for (int j =  0; j < 4; j++)
		{
			while (*p2 != '.' && *p2 != '\0')
			{
				if (*p2 >= '0'  && *p2 <= '9')
				{
					temp = temp * 10 + *p2 - '0';
				}
				//else
				//{
				//	cout << "NO1" << endl;
				//	break;
				//}	
				++p2;
			}
			if (temp < 0 || temp > 255)
			{
				cout << "NO" << endl;
				break;
			}	
			else
				flag++;

			temp = 0; ++p2;
		}
		if (flag == 4)
			cout << "YES" << endl;
	}
	else
		cout << "NO" << endl;

	
}

void main()
{
	char str[500];
	cin >> str;
	Solution(str);
}
