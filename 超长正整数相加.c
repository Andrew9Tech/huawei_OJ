#include<stdio.h>
#include<string.h>

#define BIGINTRADIX 10000
#define RADIX 4
#define MAX_LEN (100/RADIX + 1)*BIGINTRADIX

char m[MAX_LEN * RADIX], n[MAX_LEN * RADIX];
int a[MAX_LEN] = { 0 }, b[MAX_LEN] = { 0 }, c[MAX_LEN + 1] = { 0 };

void Solution(char *s1, char *s2)
{
	int i, j, k, temp, low;
	int len1 = strlen(s1), len2 = strlen(s2);
	
	j = 0;
	for (i = len1; i > 0; i -= RADIX)
	{
		temp = 0;
		low = i - RADIX > 0 ? i - RADIX : 0;
		for (k = low; k < i; k++) temp = temp * 10 + s1[k] - '0';
		a[j++] = temp;
	}
	j = 0;
	for (i = len2; i > 0; i -= RADIX)
	{
		temp = 0;
		low = i - RADIX > 0 ? i - RADIX : 0;
		for (k = low; k < i; k++) temp = temp * 10 + s2[k] - '0';
		b[j++] = temp;
	}

	for (int i = 0; i < MAX_LEN + 1; i++) c[i] = 0;
	for (i = 0; i < MAX_LEN; i++)
	{
		c[i] += a[i] + b[i];
		if (c[i]>=BIGINTRADIX)
		{
			c[i] = c[i] % BIGINTRADIX;
			c[i+1] = c[i + 1] + 1;
		}
	}

	int flag = 0;
	for (i = MAX_LEN - 1; i >= 0; --i)
	{
		if (flag)
		{
			printf("%04d", c[i]);
		}
		else if (c[i] > 0)
		{
			flag = 1;
			printf("%d", c[i]);
		}
	}
}

int main()
{
	scanf_s("%s", m, 100);
	scanf_s("%s", n, 100);
	Solution(m, n);
	return 0;
}
