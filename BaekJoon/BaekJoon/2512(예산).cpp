#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;						//지방의 수
	int m;						//총 예산
	int low = 0;				//나올 수 있는 예산 중 가장 작은 값
	int high = 0;				//high : arr 중 가장 큰 값 
	int mid;					//중간값
	int ans;					//배정된 예산들 중 최댓값
	int arr[10001];				//각 지방의 예산요청

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];

		high = max(high, arr[i]);
	}

	cin >> m;
	
	while (low <= high)							//이분탐색
	{
		mid = (low + high) / 2;

		long long sum = 0;						//min(arr,mid)의 누적합 -> m이하!

		for (int i = 0; i < n; i++)
			sum += min(arr[i], mid);

		if (sum <= m)
		{
			ans = mid;
			low = mid + 1;
		}
		else
			high = mid - 1;
	}

	cout << ans << endl;

	return 0;
}