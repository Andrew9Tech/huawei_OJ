#include<iostream>
using namespace std;

void Reverse(char* pBegin, char* pEnd)
{
	if (pBegin == NULL || pEnd == NULL)
		return;

	while (pBegin < pEnd)
	{
		char temp = *pBegin;
		*pBegin = *pEnd;
		*pEnd = temp;

		pBegin++;
		pEnd--;
	}
}

char* ReverseSentence(char* str)
{
	if (str == NULL)	return NULL;

	char* pBegin = str;
	char *pEnd = str;
	while (*pEnd != '\0')	pEnd ++;
	pEnd--;

	//翻转整个句子
	Reverse(pBegin, pEnd);

	//翻转句子中每个单词
	pBegin = pEnd = str;
	while (*pBegin != '\0')
	{
		if (*pBegin == ' ')
		{
			pBegin ++;
			pEnd ++;
		}
		else if (*pEnd == ' ' || *pEnd == '\0')
		{
			Reverse(pBegin, --pEnd);
			pBegin = ++pEnd;
		}
		else
		{
			pEnd ++;
		}
	}
	return str;
}


void main()
{
	char str[1000];
	cin.getline(str, 1000);
	cout << ReverseSentence(str) << endl;
}
