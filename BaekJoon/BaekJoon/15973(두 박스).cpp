#include <iostream>
#include <algorithm>
using namespace std;

struct rec
{
	long long x1, x2, y1, y2;
};

int main()
{
	struct rec p, q;

	cin >> p.x1 >> p.y1 >> p.x2 >> p.y2;			//사각형 p의 좌표 입력
	cin >> q.x1 >> q.y1 >> q.x2 >> q.y2;			//사각형 q의 좌표 입력

	if (p.x1 == q.x2 || p.x2 == q.x1)				//만약 p,q의 x1,x2가 같거나 x2,x1이 같을 때
	{
		if (p.y1 == q.y2 || p.y2 == q.y1)			//p,q의 y1,y2가 같거나 y2=y1이 같다면
			cout << "POINT\n";
		else if ((p.y2 - p.y1) + (q.y2 - q.y1) > max(q.y2 - p.y1, p.y2 - q.y1))	//사각형 p,q의 높이의 합 > |q의 가장 높은 y좌표 - p의 가장 낮은 좌표|
			cout << "LINE\n";
		else
			cout << "NULL\n";
	}
	else if ((p.x2 - p.x1) + (q.x2 - q.x1) > max(q.x2 - p.x1, p.x2 - q.x1))	//p,q의 가로의 합 > |q의 가장 오른쪽에 있는 x좌표 - p의 가장 왼쪽의 있는 좌표|
	{
		if (p.y1 == q.y2 || p.y2 == q.y1)			//p,1의 y1,y2가 같거나 y2,y1이 같다면
			cout << "LINE\n";
		else if ((p.y2 - p.y1) + (q.y2 - q.y1) > max(q.y2 - p.y1, p.y2 - q.y1))	//p,q의 높이의 합 > |가장 높은 y좌표 - 가장 낮은 y좌표|
			cout << "FACE\n";
		else
			cout << "NULL\n";
	}
	else
		cout << "NULL\n";




	return 0;
}