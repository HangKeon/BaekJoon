#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n, s;					//n : 수열의 길이, s : 합
	int ans = 2e9;				//s이상인 값 중에서 가장 짧은 길이
	int cnt = 0;				//s이상인 값의 길이
	int sum = 0;				//부분합
	int l, r;					//l : 시작 인덱스, r : 끝 인덱스
	int arr[100001];			//수열

	cin >> n >> s;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	l = 0, r = 0;

	while (r <= n)
	{
		if (sum < s)
		{
			sum += arr[r++];
			cnt++;
		}
		else						//sum >= s
		{
			ans = min(ans, cnt);
			sum -= arr[l++];
			cnt--;
		}
	}

	if (ans == 2e9)					//합을 만드는 것이 불가능한 경우
		cout << 0;
	else
		cout << ans;


	return 0;
}