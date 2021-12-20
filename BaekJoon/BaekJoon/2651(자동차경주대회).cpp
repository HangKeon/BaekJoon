#include <iostream>
using namespace std;

int main()
{
	int k;						//정비 받지 않고 갈 수 있는 최대거리
	int n;						//정비소 갯수
	long long arr[101];			//인접한 정비소 사이 거리
	long long arr2[101];		//정비소 별 정비 시간
	long long sum[101] = { 0, };			//거리 누적합
	int A[101], B[101];

	cin >> k >> n;

	for (int i = 1; i <= n + 1; i++)
	{
		cin >> arr[i];

		sum[i] = sum[i - 1] + arr[i];
	}

	for (int i = 1; i <= n; i++)
	{
		cin >> arr2[i];

		if (sum[i] <= k)					//누적 거리 합 <= 정비받지 않고 움직일 수 있는 최대 거리
			A[i] = arr2[i];
	}

	for (int i = 1; i <= n + 1; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if(sum[i]-sum[j]<=k)
		}
	}
	


	return 0;
}