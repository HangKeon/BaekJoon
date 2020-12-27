#include <iostream>
using namespace std;

int main()
{
	int a[5][4], sum[5] = {}, max = 0;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 4; j++)
			cin >> a[i][j];
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 4; j++)
			sum[i] += a[i][j];
	}
	for (int i = 1; i < 5; i++)
	{
		if (sum[max] < sum[i])
			max = i;
	}
	cout << max + 1 << " " << sum[max] << endl;

	return 0;
}

//го