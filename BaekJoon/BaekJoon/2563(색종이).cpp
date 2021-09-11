#include <iostream>
using namespace std;

int main()
{
	int n;						//색종이 수
	int a, b;					//색종이 붙인 위치
	int cnt = 0;				//arr이 1인 것의 개수 
	int arr[101][101] = { 0, };	//색종이를 표현할 배열

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;

		for (int j = a; j < a + 10; j++)
			for (int k = b; k < b + 10; k++)
				arr[j][k] = 1;
	}

	for (int i = 0; i < 101; i++)
		for (int j = 0; j < 101; j++)
			if (arr[i][j])
				cnt++;

	cout << cnt << endl;

	return 0;
}