#include <iostream>
using namespace std;

int main()
{
	int m, n;						//m : 가로, 세로의 크기, n : 날짜 수
	int arr[1401];					//격자칸(왼쪽 아래~왼쪽 위 ~ 오른쪽 위) -> 2*700+1
	int zero, one, two;				//0,1,2의 개수를 저장

	cin >> m >> n;

	for (int i = 0; i < 2 * m - 1; i++)		//처음 시작이 다 1이므로 1로 초기화
		arr[i] = 1;

	for (int i = 1; i <= n; i++)
	{
		cin >> zero >> one >> two;

		for (int i = zero; i < zero + one; i++)	//1만큼 증가하는 경우
			arr[i]++;

		for (int i = zero + one; i < 2 * m - 1; i++)	//2만큼 증가하는 경우
			arr[i] += 2;
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (j == 0)
				cout << arr[m - 1 - i] << ' ';
			else
				cout << arr[m - 1 + j] << ' ';
		}
		cout << endl;
	}

	return 0;
}