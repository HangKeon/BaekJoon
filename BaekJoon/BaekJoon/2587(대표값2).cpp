#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int avg = 0;				//ЦђБе
	int arr[5];

	for (int i = 0; i < 5; i++)
	{
		cin >> arr[i];

		avg += arr[i];
	}

	avg /= 5;

	//sort(arr, arr + 5);

	for (int i = 0; i < 5; i++)
	{
		for (int j = i; j < 5; j++)
		{
			if (arr[i] > arr[j])
			{
				int temp;

				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

	cout << avg << ' ' << arr[2] << endl;

	return 0;
}