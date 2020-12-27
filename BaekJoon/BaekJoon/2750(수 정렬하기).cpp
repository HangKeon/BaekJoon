#include <iostream>
using namespace std;
//선택정렬로 품

int main()
{
	int arr[1001];
	int min, temp, n, index;

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < n; i++)
	{
		min = 1001;

		for (int j = i; j < n; j++)
		{
			if (min > arr[j])
			{
				min = arr[j];
				index = j;
			}
		}

		temp = arr[i];
		arr[i] = arr[index];
		arr[index] = temp;
	}

	for (int i = 0; i < n; i++)
		cout << arr[i] << ' ';
	cout << endl;


	return 0;
}