#include <iostream>
using namespace std;
//선택정렬로 품

int main()
{
	int arr[3];
	int min, temp, index;

	for (int i = 0; i < 3; i++)
		cin >> arr[i];

	for (int i = 0; i < 3; i++)
	{
		min = 1000001;

		for (int j = i; j < 3; j++)
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

	for (int i = 0; i < 3; i++)
		cout << arr[i] << ' ';
	cout << endl;

	return 0;
}