#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n, m;                  //n : 끊어진 기타줄의 개수, m : 기타줄 브랜드
	int a, b;                  //a : 패키지 가격, b : 낱개의 가격
	int mina = 1001, minb = 1001;   //a,b,의 최솟값
	int ans = 0;

	cin >> n >> m;

	while (m--)
	{
		cin >> a >> b;

		mina = min(a, mina);
		minb = min(b, minb);
	}

	if (mina == 0 || minb == 0)
		ans = 0;
	else if (n <= 6)                  //n이 한 패키지 개수(6개) 이하인 경우
	{
		ans += min(mina, minb*n);
	}
	else                     //n이 한 패키지 개수(6개) 초과인 경우
	{
		ans += min(minb*n, (n / 6) * mina + min(mina, minb * (n % 6)));   //min(1개 가격 * n, 패키지 + 낱개)
	}

	cout << ans << endl;

	return 0;
}