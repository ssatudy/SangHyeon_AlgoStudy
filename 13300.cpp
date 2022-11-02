#include <iostream>
using namespace std;

int room[13];
int main(void)
{
	for (int i = 0; i < 13; i++)
	{
		cout << room[i] << '\n';
	}
	int N, K;
	int cnt = 0;
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		int S, Y;
		cin >> S >> Y;
		if (S==0)
		{
			Y += 6;
		}
		if (room[Y]<K)
		{
			room[Y] += 1;
		}
		else
		{
			room[Y] = 1;
			cnt += 1;
		}
	}
	for (int i = 0; i < 13; i++)
	{
		if (room[i]>0)
		{
			cnt += 1;
		}
	}
	cout << cnt;
	
	return 0;
}