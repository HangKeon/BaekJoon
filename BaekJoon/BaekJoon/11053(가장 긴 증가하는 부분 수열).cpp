#include <iostream>
using namespace std;

int main()
{
	int n;							//입력할 숫자의 갯수 
	int Max = 0;					//가장 긴 증가하는 부분 수열의 길이
	int arr[1001];					//입력하는 숫자
	int dp[1001] = { 0, };			//dp[i] : arr[i]의 값보다 작은 숫자들의 갯수 + 1(자기자신)

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < n; i++)
	{
		dp[i] = 1;					//자기자신

		for (int j = 0; j < i; j++)
		{
			if (arr[i] > arr[j])
				if (dp[i] < dp[j] + 1)
					dp[i] = dp[j] + 1;
		}

		if (Max < dp[i])
			Max = dp[i];
	}

	cout << Max << endl;

	return 0;
}