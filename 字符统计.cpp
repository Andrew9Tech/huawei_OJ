#include <iostream>
#include <algorithm>
using namespace std;

struct Count
{
	int c;
	int count;
};
bool cmp(const Count &a, const Count &b)
{
	return a.count>b.count;
}

void Solution(char* str)
{
	struct Count a[256];
	for (int i = 0; i<256; i++)
	{
		a[i].c = i;
		a[i].count = 0;
	}

	for (int i = 0; str[i] != '\0'; i++)
	{
		if ((str[i] >= 'a'&&str[i] <= 'z') || (str[i] >= 'A'&&str[i] <= 'Z') || (str[i] >= '0'&&str[i] <= '9') || str[i] == ' ')
		{
			char tmp = str[i];
			a[tmp].count++;
		}
	}
	sort(a, a + 256, cmp);
	for (int i = 0; i<256; i++)
	{
		if (a[i].count != 0)
			cout << char(a[i].c);
	}
}

void main()
{
	char str[100];
	cin.getline(str, 100);
	Solution(str);
}
