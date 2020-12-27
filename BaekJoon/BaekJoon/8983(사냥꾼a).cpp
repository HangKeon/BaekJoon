#include <iostream>
using namespace std;

int main()
{
	int n, l;						//n : 동물의 수, l: 사정거리
	int a;							//사대의 위치
	int cnt = 0;					//잡을 수 있는 동물의 수
	int x, y;						//동물의 x,y 좌표
	int dis;						//사대의 위치 ~ 동물의 위치의 거리

	cin >> n >> l;
	cin >> a;

	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;

		if (a > x)					//l a-x l + y 를 표현하기 위한 조건문
			dis = a - x + y;
		else
			dis = x - a + y;

		if (dis <= l)				//사정거리에 포함되는 경우 1증가
			cnt++;
	}

	cout << cnt << endl;

	return 0;
}