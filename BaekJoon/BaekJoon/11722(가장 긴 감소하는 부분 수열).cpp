#include <iostream>
using namespace std;

int main()
{
	int n;							//입력하는 숫자의 갯수
	int max = 0;					//가장 긴 감소하는 부분 수열의 길이
	int arr[1001];					//입력하는 숫자
	int dp[1001];					//dp[i] = 자신보다 작은 숫자의 갯수 + 1(자기자신)

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < n; i++)
	{
		dp[i] = 1;

		for (int j = 0; j < i; j++)
			if (arr[i] < arr[j])
				if (dp[i] < dp[j] + 1)
					dp[i] = dp[j] + 1;

		if (max < dp[i])
			max = dp[i];
	}

	cout << max << endl;

	return 0;
}