#include <iostream>
using namespace std;

int main()
{
	int n;
	long long int sum[81];

	sum[1] = 4;
	sum[2] = 6;

	cin >> n;

	for (int i = 3; i <= n; i++)
		sum[i] = sum[i - 1] + sum[i - 2];

	cout << sum[n] << endl;


	return 0;
}