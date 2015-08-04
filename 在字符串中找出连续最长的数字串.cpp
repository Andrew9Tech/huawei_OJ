#include <iostream>
using namespace std;
int Continuemax(char a[], char*&s)
{
	int max = 0,maxTemp = 0, index, length = strlen(a);
	for (int i = 0; i < length; i++)
	{
		int flag = i;
		while (a[flag] >= '0' && a[flag] <= '9' && a[flag])
		{
			flag++;
			maxTemp++;
		}
		if (maxTemp > max)
		{
			max = maxTemp;
			index = i;
		}
		maxTemp = 0;
	}
	s = new char[max + 1];
	for (int i = 0; i < max; i++)
		s[i] = a[i + index];
	s[max] = '\0';
	return max;
}

int main()
{
	char array[100];
	char *s;
	cin >> array;
	int length = Continuemax(array, s);
	if (length == 0)
		cout << '0' << endl;
	else
	{
		for (int i = 0; i<length; i++)
			cout << s[i];
		cout << ',' << length << endl;
	}

}
