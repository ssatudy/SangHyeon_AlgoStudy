#include <iostream>
using namespace std;

int main(void)
{
	int max_cnt = 0;
	int ncnt = 0;
	char N[8] = {};
	int num[10] = {0,};
	cin >> N;
	for (int i = 0; i<8;  i++)
	{
		if (N[i])
		{
			int n = N[i] - '0';
			if (n == 6 || n== 9)
			{
				ncnt += 1;
				if (ncnt == 2)
				{
					num[9] += 1;
					ncnt = 0;
				}
			}
			else
			{
				num[n] += 1;
			}
			
		}
	}
	if (ncnt == 1)
	{
		num[9] += 1;
	}
	for (int i = 0; i < 10; i++)
	{
		if (max_cnt < num[i])
		{
			max_cnt = num[i];
		}
	}
	cout << max_cnt;

}