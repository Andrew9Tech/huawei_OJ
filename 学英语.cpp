#include <iostream>
#include <string>
using namespace std;
string NUmberToEnglishString(long int number)
{
	string s;
	if (number<0)
	{
		s = "error";
		return s;
	}
	if (number<20)
	{
		switch (number)
		{
		case 0:
			s = "zero";
			return s;
		case 1:
			s = "one";
			return s;
		case 2:
			s = "two";
			return s;
		case 3:
			s = "three";
			return s;
		case 4:
			s = "four";
			return s;
		case 5:
			s = "five";
			return s;
		case 6:
			s = "six";
			return s;
		case 7:
			s = "seven";
			return s;
		case 8:
			s = "eight";
			return s;
		case 9:
			s = "nine";
			return s;
		case 10:
			s = "ten";
			return s;
		case 11:
			s = "eleven";
			return s;
		case 12:
			s = "twelve";
			return s;
		case 13:
			s = "thirteen";
			return s;
		case 14:
			s = "fourteen";
			return s;
		case 15:
			s = "fifteen";
			return s;
		case 16:
			s = "sixteen";
			return s;
		case 17:
			s = "seventeen";
			return s;
		case 18:
			s = "eighteen";
			return s;
		case 19:
			s = "nineteen";
			return s;
		default:
			s = "error";
			return s;
		}
	}
	if (number<100)   //21-99
	{
		if (number % 10 == 0) //20,30,40,...90的输出
		{
			switch (number)
			{
			case 20:
				s = "twenty";
				return s;
			case 30:
				s = "thirty";
				return s;
			case 40:
				s = "forty";
				return s;
			case 50:
				s = "fifty";
				return s;
			case 60:
				s = "sixty";
				return s;
			case 70:
				s = "seventy";
				return s;
			case 80:
				s = "eighty";
				return s;
			case 90:
				s = "ninety";
				return s;
			default:
				s = "error";
				return s;
			}
		}
		else
		{
			s = NUmberToEnglishString(number / 10 * 10) + ' ' + NUmberToEnglishString(number % 10);
			return s;
		}

	}
	if (number<1000)  //100-999
	{
		if (number % 100 == 0)
		{
			s = NUmberToEnglishString(number / 100) + " hundred";
			return s;
		}
		else
		{
			s = NUmberToEnglishString(number / 100) + " hundred and " + NUmberToEnglishString(number % 100);
			return s;
		}
	}
	if (number<1000000)  //1000-999999   百万以下
	{
		if (number % 1000 == 0)
		{
			s = NUmberToEnglishString(number / 1000) + " thousand";
			return s;
		}
		else
		{
			s = NUmberToEnglishString(number / 1000) + " thousand " + NUmberToEnglishString(number % 1000);
			return s;
		}
	}
	if (number<1000000000)   //十亿以下
	{
		if (number % 1000000 == 0)
		{
			s = NUmberToEnglishString(number / 1000000) + " million";
			return s;
		}
		else
		{
			s = NUmberToEnglishString(number / 1000000) + " million " + NUmberToEnglishString(number % 1000000);
			return s;
		}
	}
	if (number<9999999999)  //十亿到99亿
	{
		if (number % 1000000000 == 0)
		{
			s = NUmberToEnglishString(number / 1000000000) + " billion";
			return s;
		}
		else
		{
			s = NUmberToEnglishString(number / 1000000000) + " billion " + NUmberToEnglishString(number % 1000000000);
			return s;
		}
	}
	if (number>9999999999)
	{
		s = "error";
		return s;
	}

}
int main()
{
	long int a;
	cin >> a;
	cout << NUmberToEnglishString(a) << endl;

}
