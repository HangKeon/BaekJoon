#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	pair<int, int> p[100001];

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> p[i].first >> p[i].second;

	sort(p, p + n);

	for (int i = 0; i < n; i++)
		cout << p[i].first << ' ' << p[i].second <<"\n";

	return 0;
}