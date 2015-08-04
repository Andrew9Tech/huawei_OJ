#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp1(const int &a, const int&b)
{
	return a > b;
}

void GetLeastNumbers(const vector<int>& num, int k)
{
	int temp[k];
	int count = num.size();
	for (int i = 0; i < count; i++)
	{

	}
}


void main()
{
	int N, k;
	cin >> N;
	cin >> k;
	vector<int> array;
	for (int i = 0; i<N; i++)
	{
		int m;
		cin >> m;
		array.push_back(m);
	}
	Solution(array, k);
}
