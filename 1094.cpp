#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

template<class T>
ostream& operator<<(ostream& stream, const std::vector<T>& values)
{
	copy(begin(values), end(values), ostream_iterator<T>(stream, ", "));
	return stream;
}
int main(void)
{
	vector <int> v;
	int stick = 64;
	v.push_back(stick);
	int X;
	int res = 0;
	int flag = 0;
	cin >> X;
	while (true)
	{
		int sums = 0;
		for (int i = 0; i < v.size(); i++)
		{
			sums += v[i];
		}
		if (sums > X)
		{
			int minidx = min_element(v.begin(), v.end()) - v.begin();
			int cut = v[minidx];
			v.erase(v.begin() + minidx);
			cut = cut / 2;
			int sums2 = 0;
			if (v.size() != 0)
			{
				for (int i = 0; i < v.size(); i++)
				{
					sums2 += v[i];
				}
			}
			sums2 += cut;
			if (sums2 < X)
			{
				v.push_back(cut);
				v.push_back(cut);
			}
			else
			{
				v.push_back(cut);
			}

		}
		int new_stick = 0;
		for (int i = 0; i < v.size(); i++)
		{
			new_stick += v[i];
		}
		if (new_stick == X)
		{
			res = v.size();
			break;
		}
	}
	cout << res;
	return 0;
}