#include <iostream>
using namespace std;

//1110번 문제
int main()
{
	int N, a = 0, b = 0, c = 0, d = 0, stack = 0;		//N=입력할 숫자, stack = 사이클 횟수

	cout << "숫자를 입력해주세요 : ";
	cin >> N;

	d = N;												//d에 N을 대입

	while (1)
	{
		if (d >= 0 && d<100)							//0≤N<100이면
		{
			if (d<10)									//N<10이면
			{
				d *= 10;
			}

			a = d % 10;									//a는 N의 일의 자리를 구한 값	
			b = d / 10;									//b는 N의 십의 자리를 구한 값
			c = (a + b) % 10;							//c는 a와 b의 합의 일의 자리 값
			d = a * 10 + c;								//d = 10 * a + b인 값

			if (N != d)									//N이 c와 다르다면
			{
				stack++;								//stack에 1을 더해라
			}
			else
			{
				stack++;								//stack에 1을 더해라
				cout << stack << endl;
				return 0;
			}
		}
		else											//0≤N<100이 아니라면
		{
			cout << "다시 입력하세요!" << endl;
			cout << "숫자를 입력해주세요 : ";
			cin >> N;

			d = N;										//d에 N을 대입
		}

		if (stack>100)									//사이클 횟수가 100이 넘어가는 경우
		{												//더이상 구할 수 없다고 판단한다.
			cout << "값이 나오지 않습니다." << endl;
			return 0;
		}
	}

	return 0;
}
//중