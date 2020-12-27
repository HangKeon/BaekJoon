#include <iostream>
using namespace std;

int main()
{
	int x, y;						//x : 월 , y : 일
	int month[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };	//월마다의 날짜 수
	char* week[7] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };	//요일

	cin >> x >> y;

	for (int i = 1; i < x; i++)
		y += month[i];

	cout << week[y % 7] << endl;

	return 0;
}