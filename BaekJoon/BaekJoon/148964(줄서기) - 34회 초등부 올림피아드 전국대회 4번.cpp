#include <iostream>
using namespace std;

int main()
{
	int N, M;									//N = 학생 수, M = 순서쌍의 수
	int x, y;									//x > y
	int intro = 0;								//list 배열이 같은 값을 가지고 있는지 확인하기 위한 for문에 필요한 값!
	int check = 0;								//제일 마지막에 결과값을 내기 위해 필요한 조건을 나타낸 값!
	int list[100001] = { 0, };					//학생 수(N)에 맞는 숫자를 넣기 위한 배열! N의 범위 만큼 배열 선언!

	cin >> N >> M;

	for (int i = 1; i <= M; i++)				//순서쌍의 개수(M)만큼 for문 사용 -> 순서쌍 입력!
	{
		cin >> x >> y;
		list[x]++;								//list[x] 증가!
		list[y]--;								//list[y] 감소!
	}

	for (int i = 1; i <= N; i++)				//list 배열에 자기 자신의 인덱스를 더해 학생들이 가진 수를 구할 수 있다.
	{
		list[i] += i;
	}

	for (int i = 1; i <= N; i++)				//list 배열이 같은 값을 가지고 있는지 확인하기 위한 for문!
	{
		if (intro == 0)												//intro = 0인 경우!
		{
			for (int j = i + 1; j <= N; j++)
			{
				if (list[i] > 0 && list[i] != list[j])				//list 배열이 0보다 크고, list 배열끼리 같은 값을 가지 않을 경우
				{
					check = 1;										//check = 1 대입!
				}
				else												//if가 아닌 경우!
				{
					check = 0;										//check = 0 대입!
					intro = 1;										//intro = 1 대입!
					break;
				}
			}
		}
		else														//intro가 0이 아닌 경우 -> 즉, intro = 1인 경우!
			break;
	}

	if (check == 1)													//check = 1인 경우!
		for (int i = 1; i <= N; i++)								//list 배열을 출력!
			cout << list[i] << " ";
	else if (check == 0)											//check = 0인 경우!
		cout << "-1";												//-1을 출력!

	cout << endl;



	return 0;
}

//상