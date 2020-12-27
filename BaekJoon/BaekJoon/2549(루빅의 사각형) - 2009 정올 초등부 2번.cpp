#include <iostream>
using namespace std;

//무조건 첫 줄을 살필때, 즉 1~4 범위 내에서 값이 바뀌어 있을 경우는 가로로 이동
//그러나 첫 줄에 1~4 범위가 아니라면 무조건 열을 옮기는 것을 먼저 한다
//그리고 나서 그 다음줄부터는 무조건 행을 옮기는 것으로 생각하자!!!

int num = 1;					//arr 배열과 1 ~ 16의 숫자를 비교할 변수
int cnt = 0;					//이동 횟수
int sw;							//행(1)인지 열(2)인지 결정
int arr[4][4];					//타일모양
int dx[] = { 0,1 };				//우하
int dy[] = { 1,0 };

void move_right(int x,int y)	//오른쪽으로 이동
{
	int temp;
	sw = 1;
	
	
	int ay = y - dy[0];
	cnt++;

	if (ay < 0)
		ay = 3;

	if (arr[x][ay] == num)
	{
		int temp;




		return;
	}
		
	else
		move_right(x, ay);

	


}

void move_left()	//왼쪽으로 이동
{

}

int main()
{

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			cin >> arr[i][j];

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (arr[i][j] != num)
			{
				if (i == 0)					//첫 줄(i==0)인 경우
				{
					if (arr[i][j] >= 1 && arr[i][j] <= 4)	//첫 줄에 1 ~4 인 경우 -> 오른쪽 이동
					{
						move_right(i, j);
					}
					else			// 첫 줄에 1 ~4 가 아닌 다른 값이 들어 있다면 -> 아래쪽으로 이동
					{

					}
				}
				else						//둘째 줄부터 넷째 줄까지 -> 무조건 행으로만 이동!
				{

				}
			}
				
			num++;
		}
	}

	return 0;
}