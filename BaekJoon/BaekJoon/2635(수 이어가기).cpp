#include <iostream>
using namespace std;
//2000 초등부 1번

int main()
{
	int n;						//처음 입력할 값
	int m;						//두 번째 입력할 값
	int a;						//n의 값을 임시로 저장할 변수
	int j;						//max값인 i를 저장하는 변수
	int temp;					//첫 번째 값 - 두 번째 값을 저장할 변수
	int cnt = 1;				//규칙에 따라 만들 수 있는 최대 개수
	int max = -1;				//cnt 가 최대인 것을 저장할 변수

	cin >> n;
	
	for (int i = 1;i <= n; i++)
	{
		a = n;					//n의 값이 바뀌면 안되므로 a에 저장
		m = i;					//n보다 작거나 같은 모든 값들 중에서 cnt가 가장 큰 값을 구해야 하므로 i를 저장!

		cnt++;

		while (a - m >= 0)
		{
			int temp = m;
			m = a - m;
			a = temp;
			cnt++;
		}

		if (max < cnt)
		{
			max = cnt;
			j = i;
		}
		
		cnt = 1;
	}

	cout << max << endl;

	cout << n << ' ' << j << ' ';

	for (int i = 2; i < max; i++)
	{
		temp = j;
		j = n - j;
		n = temp;

		cout << j << ' ';
	}

	cout << endl;



	return 0;
}