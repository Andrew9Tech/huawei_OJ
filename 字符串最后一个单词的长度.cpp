//未考虑字符串中非字母情况，末尾标点符号


#include<iostream>
using namespace std;

int Solution(char *str)
{
	if (str == NULL) return NULL;

	char *p1 = str;
	char *p2 = str;
	int spaceNum = 0;
	int lenLastWord = 0;

	while (*p1 == ' ')	++p1;
	while (*p1 != '\0')
	{
		if (*p1 == ' ' && *(++p1) != ' ')	++spaceNum;
		++p1;
	}

	while (*p2 == ' ')	++p2;
	while (*p2 != '\0')
	{
		if (*p2 == ' ' && *(++p2) != ' ')	--spaceNum;
		if (spaceNum == 0)	++lenLastWord;
		++p2;
	}

	return lenLastWord;
}

void main()
{
	char string[1000];
	cin.getline(string, 1000);
	cout << Solution(string) << endl;
}
