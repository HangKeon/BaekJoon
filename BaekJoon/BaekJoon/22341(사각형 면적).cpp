#include <iostream>
using namespace std;
int main()
{
	int n, c;					//n : 종이 크기, c : 점의 갯수
	int x, y;					//점의 좌표
	int a, b;					//a: 현재 사각형의 가로 길이, b : 현재 사각형의 세로 길이

	cin >> n >> c;

	b = a = n;

	for (int i = 0; i < c; i++)
	{
		cin >> x >> y;
		if (x >= a || y >= b) 
			continue;

		if (a*y > b*x)			//가로로 자른 넓이 > 세로로 자른 넓이
			b = y;
		else 					//가로로 자른 넓이 < 세로로 자른 넓이
			a = x;
	}

	cout << a * b;
}