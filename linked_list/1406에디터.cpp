#include <iostream>
#include <algorithm>
using namespace std;

const int MX = 1000005;
char dat[MX];
int pre[MX], nxt[MX];
int unused = 1;
int curs = 0;

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
	cout << "\n\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	fill(pre, pre + MX, -1);
	fill(nxt, nxt + MX, -1);
	char s[100001] = { 0, };
	cin >> s;
	for (int i = 0; s[i] != 0; i++) {
		insert(curs, s[i]);
		curs++;
	}
	int M;
	cin >> M;
	while (M > 0) {
		M--;
		char edits;
		cin >> edits;
		if (edits == 'P') {
			char word;
			cin >> word;
			insert(curs, word);
			curs = nxt[curs];
		}
		else if (edits == 'L') {
			if (pre[curs] != -1)//문장 맨앞체크
				curs = pre[curs];
		}
		else if (edits == 'D') {
			if (nxt[curs] != -1) {
				curs = nxt[curs];
			}
		}
		else if (edits == 'B') {
			if (pre[curs] != -1) {
				erase(curs);
				curs = pre[curs];
			}
		}
	}
	traverse();
}