#include <iostream>
using namespace std;

int n;							//수열의 길이
int s = 0;						//수열 전체 합 -> 다 더한 후 4로 나눈 값 저장!
int arr[100001];				//수열
int sum[100001];				//누적합
int dp[2001][5];
long long c = 0;						//c=3인 경우 4등분이 된 것!
long long cnt = 0;					//가능한 방법의 개수

void divide(int a, int x,int y,int z,int k, int m)		//divide(시작값, s를 만족하는 인덱스 번호들)
{
	int b = a ;

	while(b--)
	{
		if (c == 3)
		{
			if (sum[a] - sum[0] == s)
			{
				cnt++;
			}

			return;
		}
	
		if (sum[a] - sum[b] == s)
		{
			c++;
			divide(b,x,);
			c--;
			
		}

		//b--;
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];

		s += arr[i];

		sum[i] = sum[i - 1] + arr[i];
	}

	s /= 4;

	divide(n,n,0,0,0,0);

	cout << cnt << endl;


	return 0;
}