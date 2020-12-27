#include <iostream>
using namespace std;

int main()
{
	int coin[] = { 500,100,50,10,5,1 };					//동전의 종류
	int money;											//물건의 가격
	int cnt = 0, i = 0;									//cnt = 잔돈의 개수
	int q;												//사용된 코인의 개수

	cin >> money;

	money = 1000 - money;								//사용하고 남은 돈을 저장

	while (1)
	{
		q = money / coin[i];
		cnt += q;
		if (q == 0)
		{
			i++;
			continue;									//이 다음을 수행하지 않고 다음 반복을 시작
		}
		money %= coin[i];

		if (money == 0)									//탈출조건
			break;

	}

	cout << cnt << endl;


	return 0;
}