#include <iostream>
using namespace std;

int main()
{
	int n;						//입력하는 숫자의 갯수
	int max = 0;				//dp중 가장 큰 값
	int arr[1001];				//입력하는 숫자
	int dp[1001];				//dp[i] : arr[i]까지 증가하는 부분 수열의 합 중 가장 큰 값(자기 자신 포함)

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < n; i++)
	{
		dp[i] = arr[i];			//자기 자신을 먼저 더함

		for (int j = 0; j < i; j++)
			if (arr[i] > arr[j])
				if (dp[i] < dp[j] + arr[i])
					dp[i] = dp[j] + arr[i];

		if (max < dp[i])
			max = dp[i];
	}

	cout << max << endl;

	return 0;
}