#include <iostream>
using namespace std;

int main()
{
	int a, b, v, cnt = 0;			//a = 낮에 올라가는 정도, b = 밤에 올라가는 정도, v = 나무 막대 높이, cnt = 나무 막대 올라가는데 걸리는 날짜

	cin >> a >> b >> v;

	//cnt = (v - b - 1) / (a - b) + 1;
	cnt = (v - a) / (a - b) + 1;

	if ((v - a) % (a - b) != 0)
		cnt++;


	cout << cnt << endl;


	return 0;
}