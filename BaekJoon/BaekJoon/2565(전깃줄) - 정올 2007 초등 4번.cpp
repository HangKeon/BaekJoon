#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[101];						//해당 위치까지의 가장 많이 설치할 수 있는 전깃줄 개수

int main()
{
	vector<pair<int, int> > v;		//한 줄에 연결된 전봇대 A,B의 번호
	int n;							//전깃줄의 개수
	int a, b;						//전봇대의 번호
	int ans = 0;					//꼬이지 않은 최대 전깃줄 개수
	
	cin >> n;

	v.push_back({ 0,0 });			//v[0]={0,0}으로 만들어서 v[1]부터 저장하도록 함

	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;

		v.push_back({ a,b });
	}

	sort(v.begin(), v.end());

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (v[i].second > v[j].second)
			{
				if (dp[j] >= dp[i])
				{
					dp[i] = dp[j] + 1;
				}
			}
		}

		ans = max(ans, dp[i]);
	}

	cout << n - ans << endl;


	return 0;
}