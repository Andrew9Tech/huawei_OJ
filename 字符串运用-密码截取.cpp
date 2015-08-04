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
	{
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
	}
	return max;
}

void main()
{
	char str1[100];
	scanf_s("%s", &str1, 100);
	int Len = strlen(str1);
	char str2[100]; int i = 0, j = Len - 1;
	while (str1[i] != '\0')
		str2[j--] = str1[i++];
	str2[Len] = '\0';
	cout << Solution(str1, str2) << endl;
}
