#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > arr;				//벡터로 이차원배열 선언

void divide(int startX,int startY,int n)	//divide(시작X, 시작Y, 한 변의 길이)
{





	divide()
}

int main()
{
	int n;											//전체 종이의 한 변의 길이
	
	cin >> n;

	//vector<vector<int> > arr(n, vector<int>(n));	//벡터로 이차원 배열 -> arr(가로의 크기, 세로의 크기)

	arr.assign(n, vector<int>(n));					//arr[n][n] 할당

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];

	divide(0, 0, n);



	return 0;
}