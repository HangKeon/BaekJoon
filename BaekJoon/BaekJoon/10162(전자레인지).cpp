#include <iostream>
using namespace std;

int main()
{
	int t;						//요리시간
	int a, b, c;				//5분, 1분, 10초 버튼을 누른 횟수

	cin >> t;

	if (t % 10 != 0)			//a,b,c는 10의 배수! 따라서 나눠떨어지지 않으면
		cout << -1 << endl;
	else						//t가 10의 배수인 경우
	{
		a = t / 300;
		t %= 300;

		b = t / 60;
		t %= 60;

		c = t / 10;
		c %= 10;

		cout << a << ' ' << b << ' ' << c << endl;
	}

	return 0;
}