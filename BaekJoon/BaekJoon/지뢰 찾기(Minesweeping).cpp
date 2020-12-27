#include <iostream>
using namespace std;

int main()
{
	char mine[101][101];								//지뢰찾기 입력할 배열
	int chg[101][101] = { 0, };							//지뢰찾기를 숫자로 바꾸는 배열
	int m, n;											//m = 행, n = 열
	int cnt = 1, mineCnt = 0;							//cnt = field 의 숫자, mineCnt = 근처에 있는 지뢰의 수
	int BIG_VALUE = 1000;

	while (1)
	{
		cin >> m >> n;

		if (m == 0 && n == 0)							//탈출조건
			break;

		for (int i = 0; i < m; i++)						//입력부분
			cin >> mine[i];
		cout << endl;

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (mine[i][j] == '*')					//지뢰라면
					chg[i][j] = BIG_VALUE;				//chg에 1000을 저장
				else									//지뢰가 아니라면
				{
					if (i - 1 >= 0 && j - 1 >= 0 && mine[i - 1][j - 1] == '*') mineCnt++;	//왼쪽 위에 지뢰가 있는 경우
					if (i - 1 >= 0 && mine[i - 1][j] == '*') mineCnt++;						//위에 지뢰가 있는 경우
					if (i - 1 >= 0 && j + 1 < n && mine[i - 1][j + 1] == '*') mineCnt++;	//오른쪽 위에 지뢰가 있는 경우
					if (j + 1 < n && mine[i][j + 1] == '*') mineCnt++;						//오른쪽에 지뢰가 있는 경우
					if (i + 1 < m && j + 1 < n && mine[i + 1][j + 1] == '*') mineCnt++;		//오른쪽 아래에 지뢰가 있는 경우
					if (i + 1 < m && mine[i + 1][j] == '*') mineCnt++;						//아래에 지뢰가 있는 경우
					if (i + 1 < m && j - 1 >= 0 && mine[i + 1][j - 1] == '*') mineCnt++;	//왼쪽 아래에 지뢰가 있는 경우
					if (j - 1 >= 0 && mine[i][j - 1] == '*') mineCnt++;						//왼쪽에 지뢰가 있는 경우

					chg[i][j] = mineCnt;

					mineCnt = 0;
				}
			}
		}

		cout << "Field #" << cnt++ << ":" << endl;	//출력부분

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (chg[i][j] == 1000)				//chg에 1000이 저장되어 있는 경우
					cout << '*';					//*을 출력
				else								//chg에 1000이 저장되어 있지 않은 경우
					cout << chg[i][j];				//chg에 저장된 값을 출력
			}
			cout << endl;
		}
		cout << endl;
	}

	return 0;
}