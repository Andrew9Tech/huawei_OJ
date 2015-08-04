#include <iostream>
using namespace std;
void main()
{
	int num, count = 0, result = 0;
	cin >> num;
	char Array[32];
	_itoa_s(num, Array, 2);
	for (int i = 0; i < strlen(Array); i++)
	{
		if (Array[i] == '1')
			count++;
		else
			count = 0;
		if (count > result)
			result = count;
	}
	cout << result << endl;
}
