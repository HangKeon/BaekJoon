#include <iostream>
using namespace std;

int main()
{
	int n, s, y;
	int arr[2][7] = { 0, };
	int cnt = 0;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> s >> y;

		arr[s][y]++;
	}

	for (int i = 0; i <= 1; i++)
	{
		for (int j = 1; j <= 6; j++)
		{
			if (arr[i][j] != 0)
				cnt++;
		}
	}

	cout << cnt << endl;

	return 0;
}