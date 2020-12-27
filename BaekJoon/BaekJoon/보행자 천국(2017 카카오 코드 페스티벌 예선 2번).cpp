#include <iostream>
using namespace std;

const int possible = 20170805;
int city_map[501][501];

int main()
{
	int m, n;														//지도가 m x n의 좌표평면으로 표현!

	cin >> m >> n;
   
	for (int i = 1; i <= m; i++)										//city_map를 0,1,2로 채워 넣기!
		for (int j = 1; j <= n; j++)
			cin >> city_map[i - 1][j - 1];

	city_map[1][1] = 0;												//출발점과 도착점의 city_map[i][j]=0이라는 조건!
	city_map[m - 1][n - 1] = 0;




	return 0;
}