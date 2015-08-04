#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	char str[1024];
	cin.getline(str, 1024);
	sort(str, str + strlen(str));
	for (int i = 0; str[i] != '\0'; i++)
		cout << str[i];
	return 0;
}
