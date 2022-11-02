#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	int A, B, C;
	int res = 0;
	int cnt[10] = {};
	cin >> A;
	cin >> B;
	cin >> C;
	res = A * B * C;
	string s = to_string(res);
	for (int i = 0; i < s.size(); i++)
	{
		switch (s[i])
		{
		case '0':
			cnt[0] += 1;
			break;
		case '1':
			cnt[1] += 1;
			break;
		case '2':
			cnt[2] += 1;
			break;
		case '3':
			cnt[3] += 1;
			break;
		case '4':
			cnt[4] += 1;
			break;
		case '5':
			cnt[5] += 1;
			break;
		case '6':
			cnt[6] += 1;
			break;
		case '7':
			cnt[7] += 1;
			break;
		case '8':
			cnt[8] += 1;
			break;
		case '9':
			cnt[9] += 1;
			break;
		}
	}
	for (int i = 0; i < 10; i++)
	{
		cout << cnt[i] << '\n';
	}
	return 0;
}