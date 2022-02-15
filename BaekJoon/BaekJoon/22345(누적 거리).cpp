#include <iostream>
#include <algorithm>
using namespace std;

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	pair<long long, long long> p[200001];
	int i, n, q, st, ed, mid, pm;
	long long h, ax[200001] = { 0 }, a[200001] = { 0 };

	cin >> n >> q;

	for (i = 1; i <= n; i++)
		cin >> p[i].second >> p[i].first;

	sort(p + 1, p + n + 1);

	for (i = 1; i <= n; i++)
	{
		a[i] = a[i - 1] + p[i].second;
		ax[i] = ax[i - 1] + p[i].first*p[i].second;
	}

	while (q--)
	{
		cin >> h;

		st = 1;
		ed = n;

		while (st <= ed)
		{
			mid = (st + ed) / 2;

			pm = p[mid].first;

			if (pm >= h)
				ed = mid - 1;
			else
				st = mid + 1;
		}

		cout << (2 * a[ed] - a[n])*h - ax[ed] * 2 + ax[n] << "\n";
	}
}