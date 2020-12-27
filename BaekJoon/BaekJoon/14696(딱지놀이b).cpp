#include <iostream>
using namespace std;

int main()
{
	int n;							//딱지 놀이의 총 라운드 수
	int num;						//라운드마다 그림의 총 개수
	int tmp;						//그림 모양을 입력받는 변수
	int a[5] = { 0, };				//A의 딱지 모양이 개수를 저장(1~4)
	int cmp[5] = { 0, };
	int round = 0;					//라운드를 저장할 변수

	cin >> n;

	//배열 a와 비교하기 위해 두번째줄을 배열cmp에 저장
	cin >> num;
	for (int i = 1; i <= num; i++)
	{
		cin >> tmp;

		cmp[tmp]++;
		round = i;						//현재 라운드를 저장
	}

	//세번째 줄부터 입력해서cmp와 비교
	for (int i = 2; i <= n; i++)
	{
		cin >> num;

		for (int j = 0; j < num; j++)
		{
			cin >> tmp;

			a[tmp]++;
		}

		for (int j = 4; j >= 1; j--)
		{
			if (a[j] > cmp[j])					//만약 a>cmp이면
			{
				memcpy(cmp, a, sizeof(a));		//배열 cmp에 배열 a를 대입
				round = i;
				break;
			}
			else if (a[j] < cmp[j])
			{
				break;
			}
		}


	}

	cout << round << endl;

	return 0;
}