#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int a;						//입력할 값
	int j = 0;					//홀수의 인덱스 -> 홀수의 갯수도 의미함
	int sum = 0;				//홀수의 합을 저장
	int arr[7];					//홀수를 저장할 배열

	for (int i = 0; i < 7; i++)
	{
		cin >> a;

		if (a % 2 != 0)			//a가 홀수인 경우만 arr에 저장 & 누적합
		{
			arr[j++] = a;
			sum += a;
		}
	}

	if (j == 0)					//홀수가 없는 경우
		cout << -1 << endl;
	else						//홀수가 있는 경우
	{
		//sort(arr, arr + j);

		for (int i = 0; i < j; i++)
		{
			for (int k = i; k < j; k++)
			{
				int temp;

				if (arr[i] > arr[k])
				{
					temp = arr[i];
					arr[i] = arr[k];
					arr[k] = temp;
				}
			}
		}

		cout << sum << endl << arr[0] << endl;
	}
	

	return 0;
}