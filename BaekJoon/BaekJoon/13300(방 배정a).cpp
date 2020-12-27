#include <iostream>
using namespace std;

int main()
{
	int n, y;
	int arr[7] = { 0, };

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> y;

		arr[y]++;
	}

	for (int i = 1; i <= 6; i++)
		cout << arr[i] << endl;


	return 0;
}