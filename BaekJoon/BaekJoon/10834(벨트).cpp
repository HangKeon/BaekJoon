#include <iostream>
using namespace std;

int main()
{
	int m;										//벨트의 개수(1<=m<=1000)
	int a, b, s;								//a = i벨트의 회전수, b = i+1벨트의 회전수, s = i+1벨트의 바퀴 회전방향 (0 : 시계방향/ 1 : 반시계방향)
	int roll = 0;								//i벨트의 회전 방향
	int count = 1;								//벨트의 회전 수

	cin >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> s;

		if (s == 1)
			roll = 1 - roll;

		count = (count / a)*b;
	}
	cout << roll << " " << count << endl;

	return 0;
}