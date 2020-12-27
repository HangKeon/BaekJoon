#include <iostream>
using namespace std;

int main()
{
	int n;
	int a[1001];
	int b[1001];

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> a[i] >> b[i];

	for (int i = 0; i < n - 1; i++)
		b[i + 1] = (b[i] / a[i + 1])*b[i + 1];

	cout << b[n - 1] << endl;


	return 0;
}