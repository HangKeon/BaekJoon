#include <iostream>
#include <algorithm>
using namespace std;

int dp[16];							//각 날짜 별 최대 금액

int main()
{
	int n;							//퇴사 전 남은 날
	int ans = 0;					//얻을 수 있는 최대 수익
	int day;						//남은 날짜
	int time[16];					//상담 기간
	int price[16];					//가격

	cin >> n;

	day = n;						//남은 날짜(n)을 대입

	for (int i = 1; i <= n; i++)
		cin >> time[i] >> price[i];
	
	for (int i = 1; i <= n; i++)
	{
		if (time[i] > day)			//걸리는 기간 > 남은 날짜 => 탈출조건
		{
			day--;					//남은 날짜를 1 감소
			continue;
		}

		dp[i] = price[i];			//자기 자신의 가격을 대입

		for (int j = 1; j < i; j++)
		{
			if (i - j >= time[j])	//(현재 날짜 - 이전 날짜) >= 걸리는 기간
			{
				dp[i] = max(dp[i], dp[j] + price[i]);	//가능한 기간 내의 최대 금액
			}
		}

		ans = max(dp[i], ans);		//최대 금액 찾기
		
		day--;						//남은 날짜를 1 감소
	}

	cout << ans << endl;

	return 0;
}