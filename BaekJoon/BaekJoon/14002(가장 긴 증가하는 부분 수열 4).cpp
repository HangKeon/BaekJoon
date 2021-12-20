#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;							//입력할 숫자의 갯수 
	int Max = 0;					//가장 긴 증가하는 부분 수열의 길이
	int arr[1001];					//입력하는 숫자
	int dp[1001] = { 0, };			//dp[i] : arr[i]의 값보다 작은 숫자들의 갯수 + 1(자기자신)
	vector<int> v[1001];			//LIS하는 값들을 저장하는 배열
	vector<int> ans;				//가장 긴 LIS를 저장하는 배열

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < n; i++)
	{
		dp[i] = 1;					//자기자신
		v[i].push_back(arr[i]);		//현재 자기 자신을 넣는다. -> 아래 for문이 실행 안되거나 자기보다 작은 값이 없을 수도 있으므로

		for (int j = 0; j < i; j++)
		{
			if (arr[i] > arr[j])
				if (dp[i] < dp[j] + 1)
				{
					v[i].clear();
					v[i] = v[j];				//v[i]에 v[j]를 복사
					v[i].push_back(arr[i]);
					dp[i] = dp[j] + 1;
				}
		}

		if (ans.size() < v[i].size())			//ans에 v[i]값을 복사
			ans = v[i];		
	}

	cout << ans.size() << endl;

	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << ' ';

	return 0;
}