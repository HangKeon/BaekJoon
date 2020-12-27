#include <iostream>
using namespace std;

int x[1000001], y[1000001];				//x,y좌표를 저장할 배열
int cnt = 0;							//x,y배열의 인덱스

void sort();							//x,y,배열을 x좌표의 오름차순으로 정렬할 함수
void check();							//(,)를 확인할 함수

int main()
{
	int n;								//꼭지점의 개수
	int tempx, tempy;					//x,y좌표	

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> tempx >> tempy;

		if (tempy > 0)					//y의 값이 0보다 큰 경우만 저장!
		{
			x[cnt] = tempx;
			y[cnt] = tempy;

			cnt++;							//다음 값을 저장하기 위해 인덱스를 1 증가
		}
	}

	sort();

	check();

	return 0;
}

void sort()						//x,y,배열을 x좌표의 오름차순으로 정렬할 함수
{
	int temp;					//임시로 저장할 변수

	for (int i = 0; i < cnt; i++)
	{
		for (int j = i + 1; j < cnt; j++)	//i의 다음 값과 정렬해야 하므로 j에 i+1을 대입
		{
			if (x[i] > x[j])				//x를 기준으로 오름차순
			{
				temp = x[i];
				x[i] = x[j];
				x[j] = temp;
											//x를 기준으로 오름차순 시  y도 같이 정렬
				temp = y[i];
				y[i] = y[j];
				y[j] = temp;
			}
		}
	}
}

void check()									//(,)를 확인할 함수
{
	int inc = 0;				//다른 봉우리에 의해 포함되지 않는 봉우리의 개수
	int notinc = 0;				//다른 봉우리를 포함하지 않는 봉우리의 개수

	int flag = 0;				//flag=0인경우 -> )인 경우, flag =1인 경우 -> (인 경우를 의미!!!
								//처음에는 (가 안 열려있으므로 )인 경우와 같으므로 flag=0으로 초기화!

	for (int i = 0; i < cnt; i++)
	{
		if (y[i] != 0)
		{
			for (int j = i + 1; j < cnt; j++)	//현재의 다음 순서부터 같은 높이의 점을 구해야 하므로 j=i+1부터 시작!
			{
				if (y[i] == y[j])	//만약 y의 값이 같은 점이 발견되면
				{
					x[i] = -1;		//-1의 의미 : (
					x[j] = 1;		//1의 의미  : )

					y[i] = 0;		//이미 사용한 y배열에는 0을 대입
					y[j] = 0;		//왜냐하면 조건에 y값은 0이 없다고 나와 있었으므로 이렇게 저장!

					break;			//y좌표가 같은 점을 찾았으므로 여기서 멈춘다.
				}
			}
		}
	}

	for (int i = 0; i < cnt; i++)
	{
		if (x[i] == -1)			//(인 경우
		{
			if (!flag)			//이전에 (인 것이 없다면
			{
				flag = 1;		//괄호가 열렸다는 의미로 flag에 1을 대입
			}
		}
		else if (x[i] == 1)		//)인 경우
		{
			if (flag)			//notinc를 의미
			{
				notinc++;
			}
			else				//inc인 경우를 의미
			{
				inc++;
			}

			flag = 0;			//괄호가 닫혔으므로( )이 나옴 ) flag를 0으로 바꾼다.
		}
	}

	cout << inc << ' ' << notinc << endl;


}