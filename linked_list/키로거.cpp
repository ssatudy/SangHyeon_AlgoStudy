#include <iostream>
#include <algorithm>
#include <string>
#define maxs 1000010
using namespace std;
char dat[maxs];
int pre[maxs], nxt[maxs];
int unused = 1;

void insert(int addr, char s) {
	dat[unused] = s;
	pre[unused] = addr;
	nxt[unused] = nxt[addr];
	if (nxt[addr] != -1) pre[nxt[addr]] = unused;
	nxt[addr] = unused;
	unused++;
}

void erase(int addr) {
	nxt[pre[addr]] = nxt[addr];
	if (nxt[addr] != -1) pre[nxt[addr]] = pre[addr];
}

void traverse() {
	int cur = nxt[0];
	while (cur != -1) {
		cout << dat[cur];
		cur = nxt[cur];
	}
	cout << "\n";
}
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int curs = 0;
		fill(dat, dat + maxs, 0);
		fill(pre, pre + maxs, -1);
		fill(nxt, nxt + maxs, -1);
		unused = 1;
		string s;
		cin >> s;
		for (int i = 0; i< s.length(); i++)
		{
			switch (s[i])
			{
			case '<':
				if (pre[curs] != -1)
				{
					curs = pre[curs];
				}
				break;
			case '>':
				if (nxt[curs] != -1) {
					curs = nxt[curs];
				}
				break;
			case '-':
				if (pre[curs] != -1) {
					erase(curs);
					curs = pre[curs];
				}
				break;
			default:
				insert(curs, s[i]);
				curs = nxt[curs];
				break;
			}
		}
		traverse();
	}

	return 0;
}