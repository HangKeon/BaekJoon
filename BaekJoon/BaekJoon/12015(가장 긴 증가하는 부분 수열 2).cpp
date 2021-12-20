#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int a[1000001], dp[1000001];
int main()
{
	int n, i, t, cnt = 0;
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> a[i];
	dp[0] = a[0];
	for (i = 1; i < n; i++)
	{
		if (dp[cnt] < a[i])
		{
			cnt++;
			dp[cnt] = a[i];
		}
		else
		{
			int s = 0, e = cnt, md;
			while (s <= e)
			{
				md = (s + e) / 2;
				if (dp[md] >= a[i])
					e = md - 1;
				else
					s = md + 1;
			}
			dp[s] = a[i]; //dp[e+1]=a[i];
		}
	}
	cout << cnt + 1;
	return 0;
}