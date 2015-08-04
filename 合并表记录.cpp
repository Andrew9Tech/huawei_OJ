#include <iostream>
#include <algorithm>
using namespace std;
struct Record
{
	int Index;
	int Value;
};
bool cmp(const struct Record a, const struct Record b)
{
	return a.Index<b.Index;
}

void main()
{
	int N;
	struct Record array[100];
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> array[i].Index >> array[i].Value;
	sort(array, array + N, cmp);

	for (int i = 0; i < N; i++)
		if (array[i].Index == array[i + 1].Index)
			array[i + 1].Value = array[i].Value + array[i + 1].Value;
		else
		{
			cout << array[i].Index << endl;
			cout << array[i].Value << endl;
		}
}
