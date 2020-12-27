#include <iostream>
using namespace std;

int main()
{
	int n;											//딱지 놀이 총 라운드 수
	int a, b;										//A,B가 내는 딱지에 나온 그림의 총 개수
	int tmp;										//A,B가 내는 딱지에 나온 그림의 번호를 저장
	char ans[1001];									//라운드마다 승자를 기록할 배열
	int cnt = 0;									//배열 ans에 승자 A,B,D를 저장

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int akid[5] = { 0, };							//A가 낸 딱지의 그림의 번호 개수(1 ~ 4)
		int bkid[5] = { 0, };							//B가 낸 딱지의 그림의 번호 개수(1 ~ 4)

		//A에 관한 코드
		cin >> a;
		for (int j = 0; j < a; j++)
		{
			cin >> tmp;
			akid[tmp]++;
		}

		//B에 관한 코드
		cin >> b;
		for (int j = 0; j < b; j++)
		{
			cin >> tmp;
			bkid[tmp]++;
		}

		int who = 0;									//A,B의 승자를 결정하는 변수

		for (int j = 4; j >= 1; j--)
		{
			if (akid[j] > bkid[j])					//만약 A > B라면
				who = 1;
			else if (akid[j] < bkid[j])				//만약 A < B라면
				who = 2;

			if (who != 0)							//who가 1 또는 2가 된 경우 탈출
				break;
		}

		if (who == 0)								//무승부인 경우
			ans[cnt] = 'D';
		else if (who == 1)							//승자가 A인 경우
			ans[cnt] = 'A';
		else if (who == 2)							//승자가 B인 경우
			ans[cnt] = 'B';

		cnt++;
	}
	

	for (int i = 0; i < n; i++)
		cout << ans[i] << endl;
	
	return 0;
}