#include<iostream>
using namespace std;

char Solution(char *str)
{
	if (str == NULL) return NULL;
	const int tablesize = 256;
	unsigned int hashTable[tablesize];
	for (int i = 0; i < tablesize; i++)
		hashTable[i] = 0;

	char* p = str;
	while (*(p) != '\0')
		hashTable[*(p++)] ++;

	p = str;
	while (*p != '\0')
	{
		if (hashTable[*p] == 1)
			return *p;
		p++;
	}
	return NULL;
}

void main()
{
	char str[200];
	cin.getline(str, 200);
	cout << Solution(str) << endl;
}
