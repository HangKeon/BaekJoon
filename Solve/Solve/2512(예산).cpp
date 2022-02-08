#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n, m;					//n : 지방의 수, m : 총 예산
	int sum = 0;				//배정된 예산들의 합
	int ans;					//배정된 예산들 중 최댓값
	int s = 0;					//가장 작은 예산
	int e = 0;					//가장 큰 예산
	int mid;					//배정될 수 있는 예산
	int arr[10001];				//지방에서 요구한 예산

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];

		e = max(arr[i], e);
	}

	cin >> m;

	while (s <= e)
	{
		mid = (s + e) / 2;
		sum = 0;

		for (int i = 0; i < n; i++)
			sum += min(arr[i], mid);

		if (sum <= m)							//배분할 수 있는 경우
		{
			ans = mid;
			s = mid + 1;
		}
		else
			e = mid - 1;
	}
	cout << ans;

	return 0;
}