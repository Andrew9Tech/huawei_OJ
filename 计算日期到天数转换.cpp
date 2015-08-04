#include <iostream>
using namespace std;

bool loopyear(int year)    //判断是否是闰年
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		return 1;
	else
		return 0;
}

int getOutDay(int year, int month, int day)
{
	int sum = 0;
	int a[12] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };
	if (loopyear(year) && month>2)  //如果是闰年且月份大于2
		sum = a[month - 1] + day + 1;
	else
		sum = a[month - 1] + day;
	return sum;
}
int main()
{
	int year, month, day;
	cin >> year;
	cin >> month;
	cin >> day;
	cout << getOutDay(year, month, day) << endl;
	return 0;
}
