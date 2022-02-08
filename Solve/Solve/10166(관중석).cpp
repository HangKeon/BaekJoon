#include <iostream>
using namespace std;

int arr[2001][2001];			//arr[분자][분모] : 0이면 한 번도 사용하지 x 경우, 1 : 이미 사용한 경우

int GCD(int a, int b)			//최대공약수 구하는 함수
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
	int a, b;					//원의 반지름
	int gcd;					//최대공약수
	int temp;					//arr값을 저장할 변수
	int cnt = 0;				//관중석 개수

	cin >> a >> b;

	for (int i = a; i <= b; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			gcd = GCD(i, j);

			temp = arr[j / gcd][i / gcd];

			if (temp == 0)
			{
				arr[j / gcd][i / gcd] = 1;
				cnt++;
			}
		}
	}

	cout << cnt << endl;

	return 0;
}