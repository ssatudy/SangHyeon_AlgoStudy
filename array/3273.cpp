#include <iostream>
#include <algorithm>
using namespace std;

	
int main(void)
{
	int N;
	cin >> N;
	int N_li[100000] = { 0, };
	int X;
	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> N_li[i];
	}
	cin >> X;
	sort(N_li, N_li + N);
	int s = 0;
	int e = N - 1;
	while (s<e)
	{
		if (N_li[s]+N_li[e] == X)
		{
			cnt += 1;
		}
		if (N_li[s] + N_li[e] < X)
		{
			s += 1;
		}
		else {
			e -= 1;
		}
	}
	cout << cnt;

}