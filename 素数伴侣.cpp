#include <iostream>
#include <algorithm>
//#include <math.h>
using namespace std;

bool Isprime(int num)
{
	if (num == 1)	return false;
	else if (num == 2) return true;
	for (int i = 2; i < num; i++)
	{
		if (num % i == 0)	return false;
	}
	return true;
}

bool Primer_patener(int num1, int num2)
{
	if (Isprime(num1 + num2))
		return true;
	else
		return false;
}

void main()
{
	int N, num[100], max = 0;
	cin >> N;
	if (N % 2 != 0 || N > 100)
		return;
	for (int i = 0; i < N; i++)
		cin >> num[i];

	sort(num, num + N);

	while (next_permutation(num, num + N))  //穷举每一种组合
	{
		int k = 0;
		for (int j = 0; j<N; j += 2)
			if (Primer_patener(num[j], num[j + 1]))	k++;
		if (max<k) max = k;
	}
	cout << max << endl;
}
