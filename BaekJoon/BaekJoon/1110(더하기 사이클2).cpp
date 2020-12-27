#include <iostream>
using namespace std;

int main()
{
	int n;								//사이클할 숫자
	int cnt = 0;						//사이클 횟수
	int a, b;
	int result; 

	cin >> n;

	result = n;							//result에 n을 복사해 저장!

	while (1)
	{
		if (n < 10)						//n<10인 경우 0을 붙여 두 자리수로 만든다.
			n *= 10;

		a = n % 10;						//1의 자리를 저장
		b = n / 10 + a;					//10의 자리 + 1의 자리

		if (b > 10)
			b %= 10;

		n = 10 * a + b;					//a를 10의 자리로, b를 1의 자리로 한 값을 저장!

		if (n < 10)						//n<10인 경우 0을 붙여 두 자리수로 만든다.
			n *= 10;	

		cnt++;							//사이클 수를 세는 변수

		if (n == result)
			break;

	}

	cout << cnt << endl;


	return 0;
}