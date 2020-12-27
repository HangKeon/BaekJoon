#include<iostream>
using namespace std;

int main()
{
	int N = 0, X = 0, num = 0, k = 0;				//N은 입력할 숫자의 갯수, num은 brr의 갯수
													//X는 입력한 숫자들 중 X보다 작은 수를 출력해내기 위한 기준값.
	cout << "N : ";									//k는 brr과 arr을 구분하기 위해서 사용.
	cin >> N;
	cout << "X : ";
	cin >> X;

	int *arr;										//N의 갯수에 맞게 입력할 숫자
	int brr[10000] = { 0, };						//arr중 X보다 작은 수들을 저장

	for (int i = 0; i < N; i++)
	{
		arr = new int[i];							//N의 갯수에 맞게 입력할 숫자
		cin >> arr[i];

		if (arr[i] < X)
		{
			brr[k] = arr[i];
			num++;
			k++;
		}
	}

	for (int i = 0; i < num; i++)
	{
		cout << brr[i] << " ";
	}

	return 0;
}

//중상