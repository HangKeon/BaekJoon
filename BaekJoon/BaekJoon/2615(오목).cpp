#include <iostream>
using namespace std;

int main()
{
	int arr[20][20];							//오목판

	for (int i = 0; i < 19; i++)
		for (int j = 0; j < 19; j++)
			cin >> arr[i][j];

	//가로 탐색
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			int k;

			if (!arr[i][j])						//알이 놓여 있지 않은 경우는 넘어감
				continue;

			for (k = 1; k < 5; k++)
				if (arr[i][j] != arr[i][j + k])	//가로방향으로 오목의 색이 다른 것이 있는 경우
					break;

			if (k < 5)							//오목의 색이 연속하면서 아직 5개를 전부 비교하지 않은 경우
				continue;

			if ((j == 14 || arr[i][j + 5] != arr[i][j]) && (j == 0 || arr[i][j - 1] != arr[i][j]))
			{
				cout << arr[i][j] << "\n" << i + 1 << ' ' << j + 1 << endl;

				return 0;
			}
		}
	}

	//세로 탐색
	for (int j = 0; j < 19; j++)
	{
		for (int i = 0; i < 15; i++)
		{
			int k;

			if (!arr[i][j])						//알이 놓여 있지 않은 경우는 넘어감
				continue;

			for (k = 1; k < 5; k++)
				if (arr[i][j] != arr[i + k][j])	//세로방향으로 오목의 색이 다른 것이 있는 경우
					break;

			if (k < 5)							//오목의 색이 연속하면서 아직 5개를 전부 비교하지 않은 경우
				continue;

			if ((j == 14 || arr[i + 5][j] != arr[i][j]) && (j == 0 || arr[i - 1][j] != arr[i][j]))
			{
				cout << arr[i][j] << "\n" << i + 1 << ' ' << j + 1 << endl;

				return 0;
			}
		}
	}

	//오른쪽 아래 탐색
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			int k;

			if (!arr[i][j])							//알이 놓여 있지 않은 경우는 넘어감
				continue;

			for (k = 1; k < 5; k++)
				if (arr[i][j] != arr[i + k][j + k])	//오른쪽 아래 방향으로 오목의 색이 다른 것이 있는 경우
					break;

			if (k < 5)								//오목의 색이 연속하면서 아직 5개를 전부 비교하지 않은 경우
				continue;

			if ((i == 14 || j == 14 || arr[i + 5][j + 5] != arr[i][j]) && (i == 0 || j == 0 || arr[i - 1][j - 1] != arr[i][j]))
			{
				cout << arr[i][j] << "\n" << i + 1 << ' ' << j + 1 << endl;

				return 0;
			}
		}
	}

	//오른쪽 위 탐색
	for (int j = 0; j < 15; j++)
	{
		for (int i = 4; i < 19; i++)
		{
			int k;

			if (!arr[i][j])							//알이 놓여 있지 않은 경우는 넘어감
				continue;

			for (k = 1; k < 5; k++)
				if (arr[i][j] != arr[i - k][j + k])	//세로방향으로 오목의 색이 다른 것이 있는 경우
					break;

			if (k < 5)								//오목의 색이 연속하면서 아직 5개를 전부 비교하지 않은 경우
				continue;

			if ((i == 4 || j == 14 || arr[i - 5][j + 5] != arr[i][j]) && (i == 14 || j == 0 || arr[i + 1][j - 1] != arr[i][j]))
			{
				cout << arr[i][j] << "\n" << i + 1 << ' ' << j + 1 << endl;

				return 0;
			}
		}
	}

	//아직 승부가 결정이 않은 경우
	cout << 0 << endl;

	return 0;
}