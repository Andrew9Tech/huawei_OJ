#include <iostream>
#include <string>
#include <stack>
#include "stdlib.h"
using namespace std;
int pri(char m)
{
	switch (m)
	{
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
		case '(':
		case ')':
			return 0;
		case '#':
			return -1;
		default:
			break;
	}
}
int getResult(string s)
{
	stack<int>value;
	stack<char>fuhao;
	s = s + "#$";
	if (s[0] == '-')
		s = "0" + s;
	int i = 0;
	string c = "";
	while (s[i] != '$')
	{
		if (s[i] <= '9'&&s[i] >= '0')
		{
			c = c + s[i];
			i++;
			while (s[i] <= '9'&&s[i] >= '0')
			{
				c = c + s[i];
				i++;
			}
			i--;
			int m = atoi(c.c_str());
			value.push(m);
			c = "";
		}

		else if (fuhao.size() == 0 || s[i] == '(' || pri(s[i]) > pri(fuhao.top()))
			fuhao.push(s[i]);
		else if (s[i] == ')')
		{
			for (; fuhao.top() != '('; fuhao.pop())
			{
				char d = fuhao.top();
				int a = value.top();
				value.pop();
				int b = value.top();
				value.pop();
				switch (d)
				{
					case '+':
					{
						a = a + b;
						break; 
					}
					case '-':
					{
						a = b - a;
						break; 
					}
					case '*':
					{
						a = a * b;
						break; 
					}
					case '/':
					{
						a = b / a;
						break; 
					}
					default:
						break;
				}
				value.push(a);
			}
			fuhao.pop();
		}
		else
		{
			for (; fuhao.size() != 0 && pri(s[i]) <= pri(fuhao.top()); fuhao.pop())
			{
				char d = fuhao.top();
				int a = value.top();
				value.pop();
				int b = value.top();
				value.pop();
				switch (d)
				{
					case '+':
					{
						a = a + b;
						break; 
					}
					case '-':
					{
						a = b - a;
						break; 
					}
					case '*':
					{
						a = a*b;
						break; 
					}
					case '/':
					{
						a = b / a;
						break; 
					}
				}
				value.push(a);
			}
			fuhao.push(s[i]);
		}
		i++;
	}
	return value.top();
}

bool calculating(string str)
{

	cout << getResult(str) << endl;
	return true;
}

int main(void)
{
	string a;
	cin >> a;
	if (calculating(a))
	{
		cout << "true" << endl;
	}
	return 0;
}
