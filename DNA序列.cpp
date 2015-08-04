#include<iostream>
#include <process.h>
using namespace std;

void Solution(char *str, int num)
{
	float MaxRatio = 0.0; 
	char *p1 = str; char *p2 = str; char *result = NULL;
	while (*p1 != '\0')
	{
		p2 = p1;
		float ratio = 0.0; int GCNum = 0;
		while (p2 - p1 < num)
		{
			if (*p2 == 'G' || *p2 == 'C')	GCNum++;
			++p2;
		}

		ratio = GCNum / float(num);
		if (MaxRatio < ratio)
		{
			result = p1;
			MaxRatio = ratio;
		}
		++p1;
	}
	
	for (int i = 0; i < num; i++)
		printf("%c", result[i]);
	system("pause");
}

void main()
{
	char str[100]; int num;
	scanf_s("%s", &str, 100);
	scanf_s("%d", &num, 10);
	Solution(str, num);
	
}
