#include <iostream>
using namespace std;

int main()
{
	int r, c;							//마을의 크기
	char map[11][11];					//빌딩(X), 길(.)을 저장
	int x[4] = { 1,-1,0,0 };			//(1,0) : 우, (-1,0) : 좌
	int y[4] = { 0,0,1,-1 };			//(0,1) : 상, (0,-1) : 하
	int cnt = 0;						//map[i][j]에서 인접한 길이 몇 개인지 세는 변수 -> 2개 이상이어야 유턴을 안함!

	cin >> r >> c;

	for (int i = 0; i < r; i++)							//문자열은 이런식으로 입력 가능
		cin>>map[i];

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (map[i][j] == '.')						//만약 map[i][j]가 길인 경우
			{
				cnt = 0;								//다른 map의 위치의 인접한 길의 개수를 세야 하므로 매번 0으로 초기화!

				for (int k = 0; k < 4; k++)				//map[i][j]의 상하좌우를 비교
				{
					int cx = i + x[k];					//cx, cy는 모두 map의 인덱스로 들어갈 변수 -> 절대로 음수가 나올 수 없다!
					int cy = j + y[k];					//또한 r,c보다 무조건 작아야 한다!!!

					if (cx < 0 || cy < 0 || cx >= r || cy >= c)
					{
						continue;
					}

					if (map[cx][cy] == '.')				//만약, 상하좌우에서 길(.)이 발견된 경우
					{
						cnt++;							//cnt 1 증가
					}
				}

				if (cnt < 2)							//만약, 하나라도 cnt<2인 경우 무조건 유턴을 해야 하므로 1을 출력
				{
					cout << '1' << endl;
					return 0;
				}
			}
		}
	}

	cout << '0' << endl;

	return 0;
}