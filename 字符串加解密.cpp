#include <iostream>
using namespace std;
void Encrypt(char aucPassword[], char aucResult[])
{
	int len = strlen(aucPassword);
	for (int i = 0; i<len; i++)
	{
		if (aucPassword[i] >= 'A'&&aucPassword[i]<'Z')//大写字母时
			aucResult[i] = (aucPassword[i] + 33);
		else if (aucPassword[i] >= 'a'&&aucPassword[i]<'z')//小写字母时
			aucResult[i] = (aucPassword[i] - 31);
		else if (aucPassword[i] == 'Z')      //特殊情况
			aucResult[i] = 'a';
		else if (aucPassword[i] == 'z')
			aucResult[i] = 'A';
		else if (aucPassword[i] >= '0'&&aucPassword[i]<'9')
			aucResult[i] = aucPassword[i] + 1;
		else if (aucPassword[i] == '9')
			aucResult[i] = '0';
	}
	aucResult[len] = '\0';
}


void unEncrypt(char aucPassword[], char aucResult[])
{

	int len = strlen(aucPassword);
	for (int i = 0; i<len; i++)
	{
		if (aucPassword[i]>'A'&&aucPassword[i] <= 'Z')//大写字母时
			aucResult[i] = (aucPassword[i] + 31);
		else if (aucPassword[i]>'a'&&aucPassword[i] <= 'z')//小写字母时
			aucResult[i] = (aucPassword[i] - 33);
		else if (aucPassword[i] == 'A')      //特殊情况
			aucResult[i] = 'z';
		else if (aucPassword[i] == 'a')
			aucResult[i] = 'Z';
		else if (aucPassword[i]>'0'&&aucPassword[i] <= '9')
			aucResult[i] = aucPassword[i] - 1;
		else if (aucPassword[i] == '0')
			aucResult[i] = '9';
	}
	aucResult[len] = '\0';
}

int main()
{
	char source1[100], result1[100], source2[100], result2[100];
	cin >> source1;
	cin >> source2;
	Encrypt(source1, result1);
	unEncrypt(source2, result2);
	cout << result1 << endl;
	cout << result2 << endl;
}
