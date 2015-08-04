#include <iostream>
#include <string>
using namespace std;

void  Solution(string Password)
{
	int countEnglihCharH = 0, countEnglihCharL = 0,  countNumber = 0, countOtherChar = 0;
	int	len = Password.size();

	for (int i = 0; i < len; i++)
	{
		if (Password[i] >= 'A' && Password[i] <= 'Z')
			countEnglihCharH++;
		else if (Password[i] >= 'a' && Password[i] <= 'z')
			countEnglihCharL++;
		else if (Password[i] >= '0' && Password[i] <= '9')
			countNumber++;
		else
			countOtherChar++;
	}
	//
	int sum = 0;
	if (len <= 4)	sum += 5;
	else if (len >= 5 && len <= 7)
		sum += 10;
	else if (len >= 8)
		sum += 25;
	//
	if (countEnglihCharH == 0 && countEnglihCharL == 0)
		sum += 0;
	else if ((countEnglihCharH > 0 && countEnglihCharL == 0) || (countEnglihCharH == 0 && countEnglihCharL > 0))
		sum += 10;
	else if (countEnglihCharH > 0 && countEnglihCharL > 0)
		sum += 20;
	//
	if (countNumber == 0)	sum += 0;
	else if (countNumber  == 1)
		sum += 10;
	else if (countNumber >= 2)
		sum += 20;
	//
	if (countOtherChar == 0)	sum += 0;
	else if (countOtherChar == 1)
		sum += 10;
	else if (countOtherChar >= 2)
		sum += 25;
	//
	int countEnglihChar = countEnglihCharH + countEnglihCharL;
	if (countEnglihChar > 0 && countNumber > 0)
		sum += 2;
	else if (countEnglihChar > 0 && countNumber > 0 && countOtherChar > 0)
		sum += 3;
	else if (countEnglihCharH > 0 && countEnglihCharL > 0 && countNumber > 0 && countOtherChar > 0)
		sum += 5;

	if (sum >= 90)
		cout << "VERY_SECURE" << endl;
	else if (sum >= 80)
		cout << "SECURE" << endl;
	else if (sum >= 70)
		cout << "VERY_STRONG" << endl;
	else if (sum >= 60)
		cout << "STRONG" << endl;
	else if (sum >= 50)
		cout << "AVERAGE" << endl;
	else if (sum >= 25)
		cout << "WEAK" << endl;
	else if (sum >= 0)
		cout << "VERY_WEAK" << endl;

}

int main()
{
	string str;
	getline(cin, str);
	Solution(str);
	return 0;
}
