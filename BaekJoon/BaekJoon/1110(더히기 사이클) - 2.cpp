#include <iostream>
using namespace std;

int main()
{
	int n, store;						//n= 사이클 할 수, store = n값을 저장해 나중에 비교할 변수
	int cnt = 0;						//사이클 길이
	int first, second;					//first = n의 십의 자리 수, second =n의 일의 자리 수
	int sum = 0;						//first & second를 저장할 값

	cin >> n;

	store = n;

	while (1)
	{
		cnt++;

		if (n < 10)						//n이 일의 자리인 경우
			n *= 10;

		if (cnt > 100)					//탈출조건
		{
			//cout << "값이 나오지 않습니다." << endl;
			break;
		}


		first = n / 10;					//십의 자리 저장
		second = n % 10;				//일의 자리 저장
		sum = (first + second) % 10;	//first + second의 일의 자리 저장
		n = second * 10 + sum;			//다시 숫자를 만들어 저장

		if (n == store)					//한 사이클이 다 성립한 경우
		{
			cout << cnt << endl;
			break;
		}
	}

	return 0;
}