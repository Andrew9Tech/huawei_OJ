#include<iostream>
using namespace std;

void Solution(char*  key, char* data, char* encrypt)
{
	int keych[26] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, keychT[26] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25 };
	int keyLen = strlen(key);
	int offsetKey = key[0] - '^' > 0 ? 32 : 0;
	for (int i = 0; i < keyLen; i++)
	{
		int keyValue = key[i] - 'A' - offsetKey;
		if (keych[i] == 0)
		{
			keychT[keyValue] = -1;
			keych[i] = keyValue;
		}
	}
	int j = 0;
	for (int i = keyLen; i < 26; i++)
	{
		while (keychT[j] == -1) j++;
		keych[i] = keychT[j];
		j++;
	}

	int offsetData = data[0] - '^' > 0 ? 32 : 0;
	int index = 0;
	for (index; index < strlen(data); index++)
	{
		encrypt[index] = char(keych[data[index] - 'A' - offsetData] + 'A' + offsetData);
	}
	encrypt[index] = '\0';
}


void main()
{
	char key[100], data[100], encrypt[100];
	cin >> key;
	cin >> data;
	Solution(key, data, encrypt);
	cout << encrypt << endl;

}
