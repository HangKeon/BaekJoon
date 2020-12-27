#include <iostream>
using namespace std;

int main()
{
	int a, b, c;						//a,b,c : 방의 정원을 나타내는 서로 다른 세 자연수
	int n;								//전체 학생 수
	int ans = 0;

	cin >> a >> b >> c >> n;

	for (int i = 0; i <= 50; i++)
	{
		for (int j = 0; j <= 50; j++)
		{
			for (int k = 0; k <= 50; k++)
			{
				if (a*i + b * j + c * k == n)
					ans = 1;

			}
		}
	}

	cout << ans << endl;


	return 0;
}