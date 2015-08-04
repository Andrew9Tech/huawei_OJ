#include<iostream>
using namespace std;

int Solution(char str1[], char str2[])
{
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	if (len1 <= 0 || len2 <= 0) return 0;

	int start1, start2;
	int max = 0; int count = 0;

	for (int i = 0; i < len1; i++)
		for (int j = 0; j < len2; j++)
		{
			start1 = i; start2 = j;
			while (str1[start1] == str2[start2] && start1 < len1 && start2 < len2)
			{
				start1++; start2++; count++;
			}
			if (count > max) max = count;
			count = 0;
		}
	return max;
}

void main()
{
	char str1[100], str2[100];
	scanf_s("%s", &str1, 100);
	scanf_s("%s", &str2, 100);
	for (int i = 0; i < strlen(str1); i++)
		str1[i] = tolower(str1[i]);
	for (int i = 0; i < strlen(str2); i++)
		str2[i] = tolower(str2[i]);
	cout << Solution(str1, str2) << endl;
}
