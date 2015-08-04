#include <iostream>
#include <string>
using namespace std;
int Min(int x, int y)
{
	return (x>y) ? y : x;
}

int StringDistance(string A, int pa, int lenA, string B, int pb, int lenB)
{
	if (pa >= lenA)    // A串为空时
	{
		if (pb >= lenB)
			return 0;
		else
			return lenB - pb;
	}
	if (pb >= lenB)    // B串为空时
	{
		if (pa >= lenA)
			return 0;
		else
			return lenA - pa;
	}

	if (A[pa] == B[pb])
		return StringDistance(A, pa + 1, lenA, B, pb + 1, lenB);
	else
	{
		int t1 = StringDistance(A, pa + 1, lenA, B, pb, lenB);
		int t2 = StringDistance(A, pa + 1, lenA, B, pb + 1, lenB);
		int t3 = StringDistance(A, pa, lenA, B, pb + 1, lenB);
		return Min(Min(t1, t2), t3) + 1;
	}
}

int main()
{
	string a, b;
	cin >> a >> b;
	int distance = StringDistance(a, 0, a.size(), b, 0, b.size());
	cout << "1/" << distance + 1 << endl;
}
