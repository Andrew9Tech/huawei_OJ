#include <iostream>
#include <string>
using namespace std;
struct vote
{
	string name;
	int count;
};
int main()
{
	int numhx, numvote, Invalid = 0;
	struct vote vt[100];
	string s[100];
	cin >> numhx;
	for (int i = 0; i < numhx; i++)
	{
		cin >> vt[i].name;
		vt[i].count = 0;
	}
	cin >> numvote;
	for (int i = 0; i < numvote; i++)
		cin >> s[i];

	for (int i = 0; i < numvote; i++)
		for (int j = 0; j < numhx; j++)
			if (vt[i].name == s[j])
				vt[i].count++;

	for (int i = 0; i < numhx; i++)
	{
		cout << vt[i].name << " : " << vt[i].count << endl;
		Invalid += vt[i].count;
	}
	cout << "Invalid" << " : " << numvote - Invalid << endl;
}
