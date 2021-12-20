#include <iostream>
using namespace std;

int main()
{
	int n;						//수열 갯수
	int m;						//구하는 합
	int sum = 0;					//arr[l]+arr[r]
	int cnt = 0;				//m을 만족하는 갯수
	int l = 0, r = 0;			//첫 번째, 두 번째 인덱스
	int arr[10001];				//수열

	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	while (r <= n)
	{
		if (sum < m)
			sum += arr[r++];
		else if (sum > m)
			sum -= arr[l++];
		else
		{
			cnt++;
			sum += arr[r++];
		}
	}

	cout << cnt << endl;

	return 0;
}