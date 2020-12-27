#include <iostream>
using namespace std;
//브루트 포스 알고리즘(완전 탐색)

int main()
{
	int arr[10];					//9명의 난쟁이의 키를 입력
	int sum = 0;					//난쟁이 9명의 키의 합
	int res = 0;					//참, 거짓 판단

	for (int i = 0; i < 9; i++)
	{
		cin >> arr[i];
		sum += arr[i];
	}

	for (int i = 0; i < 9; i++)						//난쟁이 2명의 키를 뺐을 때 100이 나오는 경우 찾기
	{
		for (int j = i + 1; j < 9; j++)
		{
			if (sum - arr[i] - arr[j] == 100)
			{
				arr[i] = 987654321;
				arr[j] = 987654321;
				res = 1;
				break;
			}
		}
		if (res)
			break;
	}

	for (int i = 0; i < 9; i++)						//크기순으로 정렬
	{
		for (int j = i + 1; j < 9; j++)
		{
			int tmp;

			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}

	for (int i = 0; i < 7; i++)
		cout << arr[i] << endl;


	return 0;
}