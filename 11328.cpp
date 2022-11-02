#include <iostream>
using namespace std;

int main(void)
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int flag = 0;
		char a[1000] = {0,};
		char b[1000] = {0,};
		int aa[26] = {0,};
		int bb[26] = { 0, };
		cin >> a >> b;
		for (int i = 0; i < 1001; i++)
		{
			aa[int(a[i]) - 97] ++;
		}
		for (int i = 0; i < 1001; i++)
		{
			bb[int(b[i]) - 97] ++;
		}
		for (int i = 0; i < 26; i++)
		{
			if (aa[i] != bb[i])
			{
				cout << "Impossible" << '\n';
				flag = 1;
				break;
			}

		}
		if (flag == 0)
		{
			cout << "Possible" << '\n';
		}
	}	
}