#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr[1000001];						//수열
int dp[1000001];						//LIS의 값을 저장하는 배열

int main()
{
	int n;								//수열의 크기
	int j = 0;							//dp의 인덱스 -> LIS의 크기
	int s = 0, e, mid;					//s : 시작 인덱스, e : dp의 끝 인덱스, mid : 중간 인덱스

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	dp[0] = arr[0];						//가장 맨 처음 값인 arr[0]를 대입

	for (int i = 1; i < n; i++)
	{
		if (dp[j] < arr[i])				//LIS 성립하는 경우
		{
			j++;
			dp[j] = arr[i];
		}
		else							//LIS가 성립하지 않는 경우 -> 작은 값이 나오는 경우
		{
			s = 0, e = j;

			while (s <= e)				//이분탐색으로 계속 작은 값을 바꿔준다
			{
				mid = (s + e) / 2;
				
				if (dp[mid] >= arr[i])
					e = mid - 1;
				else
					s = mid + 1;
			}

			dp[s] = arr[i]; //dp[e+1]=arr[i];
		}
	}

	cout << j + 1;

	return 0;
}