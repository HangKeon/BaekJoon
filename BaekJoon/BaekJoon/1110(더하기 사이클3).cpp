#include <iostream>
using namespace std;

int main()
{
	int n;							//입력값
	int cnt = 0;					//사이클 길이
	int a, b;						//a : 10의 자리, b: 1의 자리
	int sum;						//a+b를 저장할 변수
	int input;						//n을 복사할 변수
	
	cin >> n;

	input = n;

	while (1)
	{
		a = n / 10;
		b = n % 10;

		sum = (a + b) % 10;			//만약 a+b가 두자리인 경우 일의 자리만 필요!

		n = b * 10 + sum;

		cnt++;

		if (n == input)
			break;
	}

	cout << cnt << endl;

	return 0;
}