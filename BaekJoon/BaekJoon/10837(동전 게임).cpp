#include <iostream>
using namespace std;

int main()
{
	int k, c, m, n;							//k = 게임의 라운드 수, c = 입력 개수,m = 영희의 점수, n = 동수의 점수
	int cnt;								//남은 라운드 수
	int gap;								//m,n의 차이

	cin >> k >> c;

	for (int i = 0; i < c; i++)
	{
		cin >> m >> n;

		if (m == n)							//같은 경우는 항상 1 출력
			cout << "1" << endl;
		else if (m > n)						//m > n인 경우
		{
			gap = m - n;					//영희 - 동수
			cnt = k - m;					//게임 라운드 수 - 영희

			if (gap - cnt <= 2)
				cout << "1" << endl;
			else
				cout << "0" << endl;
		}
		else if (m < n)
		{
			gap = n - m;
			cnt = k - n;

			if (gap - cnt <= 1)
				cout << "1" << endl;
			else
				cout << "0" << endl;
		}
	}

	return 0;
}







/*
		if (m <= n && n > (k + m + 1) / 2)
			cout << "0" << endl;
		else if (m > n && m>(k + n) / 2 + 1)
			cout << "0" << endl;
		else
			cout << "1" << endl;

			*/
	
