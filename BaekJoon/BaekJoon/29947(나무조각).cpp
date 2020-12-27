#include <iostream>
using namespace std;
//버블정렬로 푼다

int main()
{
	int arr[5] = { 0, }, temp;
	
	for (int i = 0; i < 5; i++)
		cin >> arr[i];

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 4 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;

				for (int k = 0; k < 5; k++)
				{
					cout << arr[k] << ' ';
				}
				cout << endl;
			}
		}
	}

	return 0;
}