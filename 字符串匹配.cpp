#include <iostream>
using namespace std;
int main()
{
	char a[100], b[50];
	gets(b);
	gets(a);
	int flag = 0;
	for (int i = 0; b[i] != '\0'; i++)
		for (int j = 0; a[j] != '\0'; j++)
			if (b[i] == a[j])
			{
				flag++;
				break;
			}
	if (flag == strlen(b))
		cout << "true";
	else
		cout << "false";
}
