#include  <iostream>
using namespace std;

int a[101][4];							//도보시간, 도보 모금액, 자전거 시간, 자전거 모금액
int dp[101][100001] = { 0, };					//a[구간개수][걸리는 시간]


int main()
{
	int n, k;
	int t = 0, time = 0, cnt;				//t = t번째 구간, time = 걸리는 시간, cnt = 도보, 자전거 둘 다 k를 넘어가는지를 판단위한 변수
	int max = 0, total = 1;						// max = 최대 모금액, total = 되돌아 간 경우 0으로 바뀜

	cin >> n >> k;

	for (int i = 0; i < n; i++)
		cin >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3];

	while (1)
	{
		int temp1, temp2;				//a[t][1], a[t][3]을 임시 저장할 변수
		int s = 1;						//a[t][1] < a[t][3]이라는 조건이 실행되지 않은 경우 s=1을 유지

		temp1 = a[t][1];
		temp2 = a[t][3];
		cnt = 2;

		if (total == 0)						//이전으로 되돌아 간 경우
		{
			if (a[t][1] < a[t][3])			//돌아가기 전에 a[t][3]으로 계산했으므로 이번에는 a[t][1]로 계산해야 한다.	
			{
				a[t][3] = 0;				//따라서 a[t][3]에 0을 대입함으로써 다시 계산		
			}
			else							//돌아가기 전에 a[t][1]으로 계산했으므로 이번에는 a[t][3]로 계산해야 한다.
			{
				a[t][1] = 0;				//따라서 a[t][1]에 0을 대입함으로써 다시 계산	
			}

			total = 1;
		}

		if (a[t][1] < a[t][3])				//도보 모금액 < 자전거 모금액
		{


			time += a[t][2];
			dp[t][time] += a[t][3];

			if (t > 0)						//t>0인 경우
				dp[t][time] += dp[t - 1][time - a[t][2]];		//이전 구간의 최대 money를 더함

			if (time > k)					//time이 k보다 큰 경우
			{
				time -= a[t][2];
				dp[t][time] -= a[t][3];
				cnt--;
				a[t][3] = 0;
			}
		}

		if (a[t][1] >= a[t][3])				//도보 모금액 >= 자전거 모금액
		{
			time += a[t][0];
			dp[t][time] += a[t][1];

			if (t > 0)						//t>0인 경우
				dp[t][time] += dp[t - 1][time - a[t][0]];		//이전 구간의 최대 money를 더함

			if (time > k)					//time이 k보다 큰 경우
			{
				time -= a[t][0];
				dp[t][time] -= a[t][1];
				cnt--;
				a[t][1] = 0;
			}
		}

		if (s == 1)
		{
			a[t][3] = temp2;

			if (a[t][1] < a[t][3])				//도보 모금액 < 자전거 모금액
			{
				time += a[t][2];
				dp[t][time] += a[t][3];

				if (t > 0)						//t>0인 경우
					dp[t][time] += dp[t - 1][time - a[t][2]];		//이전 구간의 최대 money를 더함

				if (time > k)					//time이 k보다 큰 경우
				{
					time -= a[t][2];
					dp[t][time] -= a[t][3];
					cnt--;
					a[t][3] = 0;
				}
			}
		}
		a[t][1] = temp1;
		a[t][3] = temp2;

		if (cnt <= 0)						//cnt=0인 경우
		{
			t--;							//구간을 하나 뒤로 돌리기
			continue;
		}

		if (t == n - 1)						//마지막 구간에 도달한 경우
			if (max < dp[t][time])			//max < dp[t][time]
			{
				max = dp[t][time];
				break;
			}

		t++;								//잘 진행된 경우에는 구간t는 증가
	}

	cout << max << endl;


	return 0;
}