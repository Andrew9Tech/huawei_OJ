#include <iostream>
#include <string>
using namespace std;

string Solution1(string str)
{
	int length = str.size();
	for (int i = 0; i<length;)
	{
		int k = i;
		while (!isdigit(str[k]))
			k++;
		str.insert(k, "*");
		length++;
		k = k + 2;
		while (isdigit(str[k]))
			k++;
		str.insert(k, "*");
		length++;
		i = k + 2;
	}
	return str;
}

char* Solution2(char str[], int arraySize)
{
	if (str == NULL || arraySize <= 0) return NULL;
	int length = strlen(str);

	int originalLength = 0;
	int numberOfNum = 0;
	int i = 0; int sign = 0;
	while (str[i] != '\0')
	{
		++originalLength;
		if ('0' <= str[i] && str[i] <= '9')
			sign = 1;
		//if (('a' <= str[i] && str[i] <= 'z') || ('A' <= str[i] && str[i] <= 'Z'))
		else
		{
			if (sign == 1)
			{
				++numberOfNum;
				sign = 0;
			}
		}
	}

	int newLength = originalLength + numberOfNum * 2;
	if (newLength > arraySize) return NULL;

	int indexOriginal = originalLength;
	int indexNew = newLength;
	int flag = 0;
	while (indexOriginal >= 0 && indexOriginal < indexNew )
	{
		if (('0' <= str[indexOriginal] && str[indexOriginal] <= '9') && flag == 0)
		{
			str[indexNew--] = '*';
			str[indexNew--] = str[indexOriginal--];
			flag = 1;
			continue;
		}
		if (!('0' <= str[indexOriginal] && str[indexOriginal] <= '9') && flag == 1)
		{
			str[indexNew--] = '*';
			str[indexNew--] = str[indexOriginal--];
			flag = 0;
			continue;
		}

		str[indexNew--] = str[indexOriginal--];
	}
	return str;
}


int main()
{
	//方案1  用string
	string str1;
	//方案2  字符串
	//char str2[500];

	cin >> str1;
	//cin >> str2;
	cout << Solution1(str1) << endl;
	//cout << Solution2(str2, 500) << endl;
};

