#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector <int> v;
	int N, K;
	int num;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(),v.end());
	cout << v[K-1];
	return 0;
}