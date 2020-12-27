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

int main()
{
	int n, m;							//n = 소시지 수, m = 평론가 수
	int cnt = 0;						//필요한 칼질의 수

	cin >> n >> m;

	cnt = m - gcd(n, m);
	cout << cnt << endl;


	return 0;
}