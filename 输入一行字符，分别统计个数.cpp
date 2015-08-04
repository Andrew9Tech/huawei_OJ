#include <iostream>
using namespace std;

void main()
{
	char str[1000];
	int countEnglishChar = 0, countBlank = 0, countNumber = 0, countOther = 0;
	cin.getline(str, 1000);

	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] >= 'a' &&str[i] <= 'z' || str[i] >= 'A' &&str[i] <= 'Z')
			countEnglishChar++;
		else if (str[i] >= '0' &&str[i] <= '9')
			countNumber++;
		else if (str[i] == ' ')
			countBlank++;
		else
			countOther++;
	}

	cout << countEnglishChar << endl;
	cout << countBlank << endl;
	cout << countNumber << endl;
	cout << countOther << endl;
}
