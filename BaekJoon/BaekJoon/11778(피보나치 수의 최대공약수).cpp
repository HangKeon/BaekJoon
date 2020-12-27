#include <iostream>
using namespace std;

int Fibonacci(int n);								//피보나치 수열 구하는 함수
int GCD(int a, int b);								//최대공약수를 구하는 함수

int main()
{
	int n = 0, m = 0;								//n,m번 째 피보나치 수열을 사용하기 위해 입력!
	int result = 0;									//결과값
	int a = 0, b = 0;

	cout << "n 입력 : ";
	cin >> n;
	cout << "m 입력 : ";
	cin >> m;

	a = Fibonacci(n);
	b = Fibonacci(m);

	result = GCD(a, b);

	cout << result << endl;

	return 0;
}

int Fibonacci(int n)								//피보나치 수열 재귀함수로 만듬.
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int GCD(int a, int b)								//최대공약수를 유클리드 호제법으로 구함.
{
	int temp = 0;

	while (b != 0)
	{
		temp = a % b;
		a = b;
		b = temp;
	}

	return a;
}

//중하