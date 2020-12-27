#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;							//자연수의 개수
	int arr[20001];					//입력할 자연수
	int sum = 2e9;					//값들의 차이의 합
	int temp = 0;					//값들의 차이의 합을 임시 저장
	int ans;						//sum이 뽑혔을 때의 값

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);				//sum이 같은 경우 작은 값이 ans에 저장되도록 정렬

	for (int i = 0; i < n; i++)
	{
		temp = 0;

		for (int j = 0; j < n; j++)
		{
			temp += abs(arr[i] - arr[j]);
		}

		if (sum > temp)
		{
			sum = temp;
			ans = arr[i];
		}
	}

	cout << ans << endl;


	return 0;
}