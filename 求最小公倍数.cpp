#include<iostream>
using namespace std;

//最大公约数
int GCD(int num1, int num2)
{
	int temp;
	if (num1 > num2)
	{
		temp = num1;
		num1 = num2;
		num2 = temp;
	}
	if (num2%num1 == 0)
		return num1;
	else
		return GCD(num2%num1, num1);
}


//多个数的公倍数
int LCM1(int Array[])
{
	int x, y, num = Array[0], gcd;
	for (int i = 0; i < sizeof(Array); i++)
	{
		x = num; y = Array[i+1];
		gcd = GCD(x, y);
		num = (x * y) / gcd;
	}
	return num;
}



//最小公倍数
int LCM(int num1, int num2)
{
	int gcd = GCD(num1, num2);
	return (num1 * num2) / gcd;
}
void main()
{
	int num1, num2;
	cin >> num1;
	cin >> num2;
	cout << LCM(num1, num2) << endl;
}
