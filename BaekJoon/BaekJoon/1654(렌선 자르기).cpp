#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int k, n;					//k : 이미 가진 랜선 수, n : 필요한 랜선 수
	long long s = 1, e = 0;			//s : 시작값, e : 끝값
	long long mid;					//랜선 길이
	long long sum = 0;			//만들 수 있는 랜선 개수
	long long mx = 0;					//최대 랜선 길이
	long long arr[10001];				//가지고 있는 랜선의 길이를 저장하는 배열

	cin >> k >> n;

	for (int i = 0; i < k; i++)
	{
		cin >> arr[i];

		e = max(e, arr[i]);
	}

	while (s <= e)
	{
		mid = (s + e) / 2;
		sum = 0;

		for (int i = 0; i < k; i++)
			sum += (arr[i] / mid);

		if (sum < n)					//개수가 모자라는 경우
		{
			e = mid - 1;
			continue;
		}
		else
		{
			s = mid + 1;
		}		

		mx = max(mx, mid);
	}

	cout << mx << endl;

	return 0;
}