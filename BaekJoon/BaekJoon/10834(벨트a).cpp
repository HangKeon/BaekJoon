#include <iostream>
using namespace std;

int main()
{
	int m, arr[1001], roll = 0;

	cin >> m;

	for (int i = 1; i <= m; i++)
		cin >> arr[i];

	cout << roll << ' ';

	for (int i = 1; i <= m; i++)
	{
		if (arr[i] == 1)
			roll = 1 - roll;

		cout << roll << ' ';
	}

	cout << endl;
	
	return 0;
}