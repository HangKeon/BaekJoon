#include <iostream>
using namespace std;

int distance(int x, int a, int b)	//distance(사대의 위치, 동물의 x좌표, 동물의 y좌표) -> 사대와 동물사이의 거리
{
	if (x > a)
		return (x - a + b);
	else
		return (a - x + b);
}

int main()
{
	int m, n, l;						//m : 사대의 수, n : 동물의 수, l : 사정거리
	int gun[10001];						//사대의 위치
	int x, y;							//동물의 위치
	int dis;							//동물의 위치 ~ 사대의 거리
	int cnt = 0;						//각 사대가 잡은 동물의 수의 합

	cin >> m >> n >> l;

	for (int i = 0; i < m; i++)
		cin >> gun[i];

	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;

		for (int j = 0; j < m; j++)				//입력한 동물의 좌표(x,y)를 사대의 좌표와 바로 비교
		{
			dis = distance(gun[j], x, y);

			if (dis <= l)
				cnt++;
		}
	}

	cout << cnt << endl;


	return 0;
}