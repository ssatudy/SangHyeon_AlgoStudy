#include <iostream>
using namespace std;
int di[] = { 1,0,-1,0 };
int dj[] = { 0,1,0,-1 };
int i = 0;
int j = 0;
int ni;
int nj;
int dir = 0;
int ansi = 0;
int andj = 0;
int main(void)
{
	int N;
	int search;
	cin >> N;
	cin >> search;
	int** mat = new int*[N];
	for (int i = 0; i < N; i++)
	{
		mat[i] = new int[N];
		fill_n(mat[i], N, 0);
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << mat[i][j] << ' ';
		}
		cout << '\n';
	}

	while (true)
	{
		mat[i][j] = 
		ni = i + di[dir];
		nj = j + dj[dir];

	}
	return 0;
}