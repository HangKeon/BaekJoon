#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n;							//수열의 크기
	int arr[1001];					//수열
	int dp[1001];					//LIS의 개수
	vector<int> v[1001];			//각 LIS를 이루는 값들
	vector<int> ans;				//LIS가 가장 긴 값들

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < n; i++)
	{
		dp[i] = 1;								//자기 자신의 개수 
		v[i].push_back(arr[i]);					//자기 자신을 저장

		for (int j = 0; j < i; j++)
			if (arr[j] < arr[i] && dp[i] < dp[j] + 1)
			{
				dp[i] = dp[j] + 1;

				v[i].clear();					//비우기
				v[i] = v[j];					//여태까지의 값을 복사
				v[i].push_back(arr[i]);			//다시 자기 자신을 마지막에 추가
			}

		//ans = max(ans, dp[i]);
		
		if(ans.size()<v[i].size())				//LIS의 개수가 더 크면 바꿈
			ans = v[i];
	}

	cout << ans.size() << endl;

	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << ' ';

	return 0;
}