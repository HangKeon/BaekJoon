#include <iostream>
using namespace std;

int main()
{
	int n, m, k;					//n : 행, m : 열, k : o로 표시된 칸의 번호
	int arr[16][16] = { 0, };		//격자의 위치에 있는 수를 저장
	int midx, midy;					//k!=0인 경우 k의 좌표를 저장할 변수
	int value;						//k!=0인 경우 k까지의 경로의 개수를 저장할 변수
	arr[0][1] = 1;					//arr[0][1]이나 arr[1][0]을 1로 초기화가 필요하다.

	cin >> n >> m >> k;

	if (k != 0)						//k가 0이 아닌 경우 -> 어딘가를 한 번 거쳐야 하는 경우
	{
		midx = k / m + (k%m > 0 ? 1 : 0);

		if (k%m == 0)
			midy = m;
		else
			midy = k % m;

		for (int i = 0; i <= midx; i++)
			for (int j = 0; j <= midy; j++)
				arr[i][j] = arr[i][j - 1] + arr[i - 1][j];

		value = arr[midx][midy];

		arr[midx][midy] = 1;		//다시 여기서부터 새로 시작하기 위해 1로 초기화

		for (int i = midx; i <= n; i++)
			for (int j = midy; j <= m; j++)
				arr[i][j] = arr[i][j - 1] + arr[i - 1][j];

		value *= arr[n][m];			//최종 경로의 수를 value에 저장
	}
	else							//k가 0인 경우 -> 어딘가를 거치지 않는 경우
	{
		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= m; j++)
				arr[i][j] = arr[i][j - 1] + arr[i - 1][j];

		value = arr[n][m];			//최종 경로의 수를 value에 저장

	}

	cout << value << endl;

	return 0;
}