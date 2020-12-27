#include <iostream>
using namespace std;

#include <iostream>
#include <algorithm>						//최솟값 구분하는 min함수를 쓰기 위해
using namespace std;

int main()
{
	int n;											//시작하는 값
	int dp[100001];									//dp[n] -> n까지 도달하는 최소 경우의 수

	cin >> n;

	dp[1] = 0;										//1에서 1까지 도달하는 최소 경우의 수 = 0가지

	for (int i = 2; i <= n; i++)
	{
		dp[i] = dp[i - 1] + 1;						//3번 -> 1을 빼는 경우

		if (i % 2 == 0)								//2번 -> 2로 나누어 떨어지는 경우
			dp[i] = min(dp[i], dp[i / 2] + 1);
		if (i % 3 == 0)								//1번 -> 3으로 나누어 떨어지는 경우
			dp[i] = min(dp[i], dp[i / 3] + 1);
	}

	cout << dp[n] << endl;

	return 0;
}












/*
//1463번
int min(int a, int b);

int main()
{
	int N;
	int *Dp;										//동적생성

	cout << "숫자를 입력하시오 : ";
	cin >> N;
	
	while (1)
	{
		if (N <= 0)									//입력한 N이 0보다 작거나 같을 경우
		{
			cout << "숫자를 다시 입력하세요 : ";	//다시 입력
			cin >> N;
		}
		else										//입력한 N이 0보다 큰 경우
		{
			Dp = new int[N + 1];							
			Dp[1] = 0;								//N=1인 경우 최소값이 0이기 때문이다.

			for (int i = 2; i <= N; i++)
			{
				Dp[i] = Dp[i - 1] + 1;					//1을 뺀 경우

				if (i % 2 == 0)							//2로 나누어 떨어지는 경우
					Dp[i] = min(Dp[i], Dp[i / 2] + 1);

				if (i % 3 == 0)							//3으로 나누어 떨어지는 경우
					Dp[i] = min(Dp[i], Dp[i / 3] + 1);
			}
			break;
		}
	}

	cout << "최소 횟수 : " << Dp[N] << endl;

	return 0;
}

int min(int a, int b)								//최소값을 정하는 함수
{
	return a < b ? a : b;							//a<b -> a
}													//아니면 -> b 를 출력

//상
*/