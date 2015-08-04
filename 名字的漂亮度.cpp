#include<iostream>
#include<algorithm>
#include<ctype.h>
using namespace std;
int Beauty(char a[])  //计算一个字符串的最大漂亮度
{
	int b[26] = { 0 };  //存储每个字符的个数
	int sum = 0;
	for (int i = 0; a[i] != '\0'; i++)
		a[i] = tolower(a[i]);  //全部先转换成小写
	for (int i = 0; a[i] != '\0'; i++)
		b[a[i] - 97]++;
	sort(b, b + 26);
	for (int i = 25; i >= 0; i--)
		sum += (i + 1)*b[i];
	return sum;
}

int main()
{
	int M;
	char array[100][100];
	cin >> M;
	getchar(); //清除回车
	for (int i = 0; i<M; i++)
		gets(array[i]);
	for (int i = 0; i<M; i++)
		cout << Beauty(array[i]) << endl;
	return 0;
}
