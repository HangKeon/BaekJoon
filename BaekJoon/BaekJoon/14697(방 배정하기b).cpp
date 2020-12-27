#include <iostream>
using namespace std;

int main()
{
	int a, b, n;					//a,b : 방의 정원, n : 전체 학생 수
	int ans = 0;					//빈 침대 없이 배정 가능한지 결정하는 변수

	cin >> a >> b >> n;

	for (int i = 0; i <= 50; i++)
	{
		for (int j = 0; j <= 50; j++)
		{
			if (a*i + b * j == n)
			{
				ans = 1;
				break;
			}
		}
	}

	cout << ans << endl;


	return 0;
}