#include <iostream>
using namespace std;

int main()
{
	int n, index, min, value;			//n = 학생 수, index = 최소값의 인덱스 저장, min = 최소값 저장, value = 가장 높은 점수 - 가장 낮은 점수
	int tmp;							//임시값 저장
	int arr[1001];						//학생 점수 저장

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < n; i++)
	{
		min = 9999;

		for (int j = i; j < n; j++)
		{
			if (min > arr[j])
			{
				min = arr[j];
				index = j;
			}
		}

		tmp = arr[i];
		arr[i] = arr[index];
		arr[index] = tmp;
	}

	value = arr[n - 1] - arr[0];

	cout << value << endl;





	return 0;
}