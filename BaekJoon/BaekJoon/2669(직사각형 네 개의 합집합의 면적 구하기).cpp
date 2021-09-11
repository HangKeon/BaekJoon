#include <iostream>
using namespace std;

int main()
{
	int a, b, c, d;
	int t = 4;
	int cnt = 0;						//1ÀÇ °¹¼ö ÀúÀå
	int arr[101][101] = { 0, };

	while (t--)
	{
		cin >> a >> b >> c >> d;

		for (int i = a; i < c; i++)
			for (int j = b; j < d; j++)
				arr[i][j] = 1;
	}

	for (int i = 0; i <= 100; i++)
		for (int j = 0; j <= 100; j++)
			if(arr[i][j])
				cnt++;

	cout << cnt << endl;

	return 0;
}