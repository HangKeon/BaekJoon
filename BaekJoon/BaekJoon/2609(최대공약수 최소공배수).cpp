#include <iostream>
using namespace std;

int gcd(int a, int b)					//최대공약수
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

int lcm(int a, int b)					//최소공배수
{
	return a * b / gcd(a, b);
}

int main()
{
	int a, b;							//입력값

	cin >> a >> b;

	cout << gcd(a,b) << endl << lcm(a,b) << endl;


	return 0;
}