#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	int cnt1[26] = { 0, };
	int cnt2[26] = { 0, };
	int cnt = 0;
	string s1, s2;
	cin >> s1;
	cin >> s2;

	for (int i = 0; i < s1.length(); i++)
	{
		cnt1[int(s1[i]) - 97] ++;
	}
	for (int i = 0; i < s2.length(); i++)
	{
		cnt2[int(s2[i]) - 97] ++;
	}
	for (int i = 0; i < 26; i++)
	{
		cnt += abs(cnt1[i] - cnt2[i]);
	}
	cout << cnt;
}