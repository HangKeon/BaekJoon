#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n, s;					//n : 수열의 갯수, s : 합
	int l, r;					//l : 시작 범위 인덱스,  r : 끝 범위 인덱스
	int sum = 0;				//부분합
	int cnt = 0;				//합이 s이상의 길이
	int ans = 2e9;				//합이 s 이상인 것 중 가장 짧은 길이
	int arr[100001];			//수열

	cin >> n >> s;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	l = 0, r = 0;

	while (r<=n)
	{
		if (sum < s)
		{
			sum += arr[r++];
			cnt++;
		}
		else
		{
			ans = min(cnt, ans);
			sum -= arr[l++];
			cnt--;
		}
	}

	if (ans == 2e9)
		cout << 0 << endl;
	else
		cout << ans << endl;

	return 0;
}