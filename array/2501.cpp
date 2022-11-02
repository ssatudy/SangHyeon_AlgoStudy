#include <iostream>

using namespace std;

int main(void)
{
	int N, K;
	int cnt = 0;
	int res = 0;
	cin >> N >> K;
	for (int i = 1; i < N+1; i++)
	{
		if (N%i == 0)
		{
			cnt++;
			if (cnt == K)
			{
				res = i;
			}
		}
	}
	cout << res ;
	return 0;
}