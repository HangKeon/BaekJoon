#include <iostream>
using namespace std;

int arr[1001][1001];			//색종이가 놓이는 곳

int main()
{
	int n;						//색종이의 장수
	int a, b, c, d;				//a,b : 색종이 가장 왼쪽 아래, c : 너비, d : 높이
	int cnt[101] = { 0, };		//각 사각형의 보이는 면적을 기록

	cin >> n;

	for (int i = 1; i <= n; i++)	//i를 면적을 표현할 때 사용하기 위해!
	{
		cin >> a >> b >> c >> d;

		for (int j = a; j < a + c; j++)
			for (int k = b; k < b + d; k++)
				arr[j][k] = i;
	}

	for (int i = 0; i <= 1000; i++)
		for (int j = 0; j <= 1000; j++)
			cnt[arr[i][j]]++;

	for (int i = 1; i <= n; i++)
		cout << cnt[i] << endl;



	return 0;
}