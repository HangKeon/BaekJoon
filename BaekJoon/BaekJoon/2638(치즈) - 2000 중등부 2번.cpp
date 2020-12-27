#include <iostream>
using namespace std;

int n, m;				//모눈종이의 크기
int arr[101][101];		//모눈종이 -> 1 : 치즈가 o, 0 : 치즈가 x
const int DX[4] = { -1,1,0,0 }, DY[4] = { 0,0,-1,1 };

int allMelted() 
{
	int i, j, count = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (arr[i][j] == 1 || arr[i][j] == 2) {
				arr[i][j] = 1;
				count++;
			}
			else arr[i][j] = 0;
		}
	}
	return count;
}


void dfs(int x,int y)
{
	int i, ax, ay;
	arr[x][y] = -1;				//arr[x][y]는 무조건 0이므로 -1로 바꾼다.

	for (i = 0; i < 4; i++) 
	{
		ax = x + DX[i]; 
		ay = y + DY[i];

		if ((0 <= ax && ax < n) && (0 <= ay && ay < m)) 
		{
			if (arr[ax][ay] > 0) 
				arr[ax][ay]++;
			else if (arr[ax][ay] == 0) 
				dfs(ax, ay);
		}
	}

}


int main()
{
	int k;						//걸리는 시간
	

	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];

	for (k = 0; allMelted(); k++)		//allMelted가 0이 되는 순간의 k값이 걸리는 시간!
		dfs(0, 0);

	cout << k << endl;


	return 0;
}