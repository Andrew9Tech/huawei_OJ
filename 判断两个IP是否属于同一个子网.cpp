#include <iostream>
using namespace std;

void CharToInt(char* str, int* Int)
{
	int i = 0, k = 0, temp = 0;
	while (str[i] != '\0' && i < strlen(str))
	{
		while (str[i] != '.' && str[i] != '\0')
		{
			temp = temp * 10 + str[i] - '0';
			i++;
		}
		Int[k++] = temp;
		temp = 0; i++;
	}
}


bool IpLegal(char* str)
{
	if (str == NULL) return false;
	int count = 0, i = 0;
	char *p = str;
	for (int i = 0; i < strlen(str); i++)
		if (str[i] == '.' && str[i + 1] != '.')
			count++;

	char *p2 = str;
	if (count == 3)
	{
		int k = 0, temp = 0, flag = 0;
		for (int j = 0; j < 4; j++)
		{
			while (*p2 != '.' && *p2 != '\0')
			{
				if (*p2 >= '0'  && *p2 <= '9')
				{
					temp = temp * 10 + *p2 - '0';
				}
				//else
				//{
				//	cout << "NO1" << endl;
				//	break;
				//}	
				++p2;
			}
			if (temp < 0 || temp > 255)
			{
				return false;
				break;
			}
			else
				flag++;

			temp = 0; ++p2;
		}
		if (flag == 4)
			return true;
	}
	else
		return false;


}

char Solution(char* mask, char* ip1, char* ip2)
{
	if (!IpLegal(mask) || !IpLegal(ip1) || !IpLegal(ip2))
		return '1';

	int maskArray[4], ip1Array[4], ip2Array[4];
	CharToInt(mask, maskArray);
	CharToInt(ip1, ip1Array);
	CharToInt(ip2, ip2Array);

	int temp1[4], temp2[4];
	for (int i = 0; i < 4; i++)
	{
		temp1[i] = maskArray[i] & ip1Array[i];
		temp2[i] = maskArray[i] & ip2Array[i];
		if (temp1[i] != temp2[i])
			return '2';
	}
	return '0';
}
void main()
{
	char Mask[20], ip1[20], ip2[20];
	cin >> Mask;
	cin >> ip1;
	cin >> ip2;
	cout << Solution(Mask, ip1, ip2) << endl;
}
