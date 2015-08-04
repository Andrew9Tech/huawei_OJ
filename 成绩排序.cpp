#include <iostream>
#include <algorithm>
using namespace std;

struct student
{
	char name[20];
	int score;
};

bool compare0(student A, student B)
{
	return A.score > B.score;
}
bool compare1(student A, student B)
{
	return A.score < B.score;
}

void main()
{
	int N, flag;
	cin >> N;
	student array[100];
	cin >> flag;
	for (int i = 0; i<N; i++)
		cin >> array[i].name >> array[i].score;

	if (flag == 0)
		sort(array, array + N, compare0);
	if (flag == 1)
		sort(array, array + N, compare1);
	for (int i = 0; i<N; i++)
		cout << array[i].name << " " << array[i].score << endl;
}
