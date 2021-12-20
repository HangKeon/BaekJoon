#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n, m;						//n : 수열 갯수, m : 차이
	int dis;						//가장 짧은 차이
	int ans = 2e9;					//가장 작은 차이의 값
	int l = 0, r = 1;				//첫 번째, 두 번째 인덱스
	int arr[100001];				//수열

	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);

	while (l < n)					//첫 번째 인덱스가 n-1에 도달할 때까지 진행
	{
		dis = arr[r] - arr[l];

		if (dis < m)				//dis가 구해야 하는 값(m)보다 작은 경우
		{
			r++;
			continue;
		}
		else if (dis == m)			//dis가 구해야 하는 값(m)보다 같은 경우
		{
			ans = m;
			break;
		}

		ans = min(ans, dis);
		l++;
	}

	cout << ans << endl;

	return 0;
}