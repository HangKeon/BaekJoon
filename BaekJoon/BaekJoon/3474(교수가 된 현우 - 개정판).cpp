#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long 

int main()
{
	int t, k = 0, m = 0;
	int *v;

	cin >> t;
	v = new int[t];
	k = t;												//아래 출력을 위해 k에 t를 대입

	while (t--)											//소인수분해를 이용하는 것
	{
		int n;
		cin >> n;

		ll cnt2 = 0, cnt5 = 0;							//cnt2 = 2로 나누었을 때의 값, cnt5 = 5로 나누었을 때의 값

		for (int i = 2; i <= n; i *= 2)					//2로 나눈 경우
		{
			cnt2 += n / i;
		}

		for (int i = 5; i <= n; i *= 5)					//5로 나눈 경우
		{
			cnt5 += n / i;
		}

		v[m++] = min(cnt2, cnt5);						//cnt2와 cnt5 중 작은 값을 넣는다.

	}

	for (int i = 0; i <k; i++)
		cout << v[i] << endl;

	return 0;
}


