#include <iostream>
using namespace std;


char* Reverse(char *s)
{
	if (s == NULL)	return NULL;

	char *pBegin = s;
	char *pEnd = s;
	while (*pEnd != '\0')
		pEnd++;
	pEnd--;

	while (pBegin < pEnd)
	{
		char temp = *pBegin;
		*pBegin = *pEnd;
		*pEnd = temp;

		pBegin++;
		pEnd--;
	}
	return s;
}

int main()
{
	char str[500];
	cin.getline(str, 500);
	cout << Reverse(str) << endl;
	return 0;
}
