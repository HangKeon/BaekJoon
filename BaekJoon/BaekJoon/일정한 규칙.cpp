#include <iostream>
using namespace std;

int main() 
{
	int n;						//몇 번째 수
	int cnt = 0;				//갯수를 세주는 변수
	int sum = 0;				//첫 번째 수부터 n번째 수까지의 합
	int j;						//찾아야 하는 n번째 수
	int sw = 0;					//sw=1이면 반복문 탈출

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		for (j = 1; j <= i; j++)
		{
			cnt++;
			sum += j;

			if (cnt == n)
			{
				sw = 1;
				break;
			}
		}

		if (sw) break;
	}

	cout << j << endl << sum << endl;

	return 0;
}