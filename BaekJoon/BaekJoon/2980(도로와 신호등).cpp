#include <iostream>
using namespace std;

int main()
{
	int n, l;						//n = 신호등의 개수, l = 도로의 길이
	int d, r, g;					//d = 신호등의 위치, r = 빨간색이 지속되는 시간, g = 초록색이 지속되는 시간
	int time = 0, preD = 0;			//time = d 위치에 도착하는 데 걸리는 시간, preD = d까지 이동한 거리
	int total = 0;					//total = 도로 끝까지 이동하는데 걸리는 시간

	cin >> n >> l;

	for (int i = 0; i < n; i++)
	{
		cin >> d >> r >> g;

		time += d - preD;			//d(신호등의 위치)까지 걸린 시간 = d이므로 저런 식을 더함 
									//preD를 빼주는 이유는 신호등이 여러 개 있는 경우는 앞의 신호등만큼 제외해주어야 하기 때문
		preD = d;

		int wait = time % (r + g);	//wait = 신호등까지 도착한 시간 % (빨간 불이 지속되는 시간 + 초록 불이 지속되는 시간)
									//wait을 선언하는 이유 : wait < r 인 경우는 신호등 앞에서 기다려야 하기 때문
		if (wait <= r)
			time += r - wait;		//time에 (빨간 불이 지속되는 시간 - 신호등에 도착하는데 걸린 시간) 을 더해준다.
	}

	total = time + (l - d);			//total = time(d 위치에 있는 신호등까지 도착하는데 걸리는 시간) + (도로의 길이 - d)

	cout << total << endl;

	return 0;
}