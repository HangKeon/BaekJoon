#include <iostream>
using namespace std;

int v[2001][2001], cnt;                //v[분모][분자] : 관중석의 위치를 분수로 만들어 기약분수가 같은 위치는 제외, cnt = 관중석 개수

int gcd(int a, int b)                 //최대공약수
{
	int c;

	while (b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main()
{
	int a, b;

	cin >> a >> b;

	for (int i = a; i <= b; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			int sum = gcd(i, j);

			if (!v[i / sum][j / sum])                    //v[i/sum][j/sum]이 중복이 아닌 경우
			{
				v[i / sum][j / sum] = 1;                  //이미 관중석 자리를 차지했더나는 것을 표시
				cnt++;                              //관중석 개수 1 증가
			}
		}
	}

	cout << cnt << endl;


	return 0;
}