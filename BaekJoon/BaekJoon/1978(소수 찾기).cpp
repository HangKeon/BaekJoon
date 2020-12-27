#include <iostream>
using namespace std;

int main()
{
	int n;								//입력할 숫자의 개수
	int prime;							//입력한 숫자
	int cnt = 0;						//소수의 개수

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> prime;

		//if (prime <= 1)					//만약 prime이 1인 경우
		//	continue;					//무시

		if (prime > 1)
		{

			for (int j = 2; j < prime; j++)	//소수 판별
			{
				if (prime%j == 0)			//나눠떨어지면
					prime = 0;				//prime을 0으로 바꿈
			}

			if (prime != 0)					//소수인 경우
				cnt++;						//cnt를 1 증가
		}
	}

	cout << cnt << endl;

	return 0;
}