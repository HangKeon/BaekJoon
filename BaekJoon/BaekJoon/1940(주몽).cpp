#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;						//재료의 갯수
	int m;						//갑옷을 만드는데 필요한 수
	int l, r;					//인덱스의 첫 번째, 마지막
	int sum = 0;				//m을 만족하는 값
	int cnt = 0;				//만들 수 있는 갑옷의 갯수
	int arr[15001];				//고유한 번호 저장

	cin >> n >> m;

	l = 0;
	r = n - 1;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);

	while (l < r)
	{
		sum = arr[l] + arr[r];

		if (sum < m)
			l++;
		else if (sum > m)
			r--;
		else
		{
			cnt++;
			l++;
			r--;
		}
	}

	cout << cnt << endl;

	return 0;
}