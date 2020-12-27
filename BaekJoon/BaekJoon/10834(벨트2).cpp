#include <iostream>
using namespace std;

int main()
{
	int n;
	int a[1001], b[1001];
	int c[1001], d[1002] = { 0, };

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> a[i] >> b[i] >> c[i];

	for (int i = 0; i < n; i++)
	{
		if (c[i] == 0)
		{
			if (d[i] == 0)
			{
				d[i + 1] = 0;
			}
			else
			{
				d[i + 1] = 1;
			}
		}
		else if (c[i] == 1)
		{
			if (d[i] == 0)
			{
				d[i + 1] = 1;
			}
			else
			{
				d[i + 1] = 0;
			}
		}
	}

	for(int i=0;i<n-1;i++)
		b[i + 1] = (b[i] / a[i + 1])*b[i + 1];

	cout << d[n] << ' ' << b[n - 1] << endl;


	return 0;
}