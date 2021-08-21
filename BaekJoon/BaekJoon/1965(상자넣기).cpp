#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;						//상자의 개수
	int ans = 0;				//입력 예제에서 넣을 수 있는 상자의 최대 갯수
	int arr[1001];				//상자의 크기
	int dp[1001] = { 1, 0 };	//각 상자에 넣을 수 있는 최대 상자의 개수(자기 자신 포함)

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			if (arr[i] > arr[j])			//앞의 상자 크기(arr[j])보다 뒤의 상자 크기(arr[i])가 크다면
				dp[i] = max(dp[i], dp[j]);

		dp[i]++;							//가장 겉에 있는 상자의 개수를 포함!

		ans = max(ans, dp[i]);
	}
	
	cout << ans << endl;

	return 0;
}