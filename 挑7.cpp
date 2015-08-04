#include<iostream>
#include <stdlib.h>
using namespace std;

int Solution(int N)
{
	int num = 0;
	for (int i = 1; i <= N; i++)
		if (i % 7 == 0)
			num++;
		else
		{
			char str[10];
			_itoa_s(i, str, 10, 10);
			for (int j = 0; j<strlen(str); j++)
				if (str[j] == '7')
				{
					num++;
					break;
				}
		}
	return num;
}

void main()
{
	int N;
	cin >> N;
	cout << Solution(N) << endl;
}
