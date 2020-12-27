#include <iostream>
using namespace std;

int main()
{
	int n;						//수열의 크기
	int arr[100001];			//수열을 저장할 공간
	int m;						//쿼리의 개수
	int a, b, c;				//입력하는 쿼리 값
	int tcnt = 0, cnt = 0;		//tcnt : 짝수의 개수, cnt : 홀수의 개수

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];

		if (arr[i] % 2 == 0)
			tcnt++;
		else
			cnt++;
	}

	cin >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;

		if (a == 1)					//arr[b]를 c로 바꾼다
		{
			if (arr[b] % 2 == 0)	//기존 arr[b]가 짝수인 경우
			{
				if (c % 2 == 1)		//c가 홀수인 경우
				{
					tcnt--;			//짝수 개수 감소
					cnt++;			//홀수 개수 증가
				}
			}
			else					//기존 arr[b]가 홀수인 경우
			{
				if (c % 2 == 0)		//c가 짝수인 경우
				{
					tcnt++;			//짝수 개수 증가
					cnt--;			//홀수 개수 감소
				}
			}
			
			arr[b] = c;

		}
		else if (a == 2)			//b ~ c 에 속하는 arr중 짝수 개수를 출력 
		{
			int k = 0;				//b~c 범위를 제외한 짝수의 개수

			for (int j = 1; j < b; j++)
			{
				if (arr[j] % 2 == 0)
					k++;
			}

			for (int j = c + 1; j <= n; j++)
			{
				if (arr[j] % 2 == 0)
					k++;
			}

			cout << tcnt - k << endl;
		}
		else						//b ~ c 에 속하는 arr중 홀수 개수를 출력
		{
			int k = 0;				//b~c 범위를 제외한 홀수의 개수		

			for (int j = 1; j < b; j++)
			{
				if (arr[j] % 2 == 1)
					k++;
			}

			for (int j = c + 1; j <= n; j++)
			{
				if (arr[j] % 2 == 1)
					k++;
			}

			cout << cnt - k << endl;
		}
	}

	return 0;
}