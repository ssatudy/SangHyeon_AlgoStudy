#include <iostream>
using namespace std;

int main(void)
{
	int N,num;
	int s[201] = {};
	int v;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		s[num + 100] += 1;
	}
	cin >> v;
	cout << s[v + 100];
	return 0;
}