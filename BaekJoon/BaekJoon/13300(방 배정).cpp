#include <iostream>
using namespace std;

int main()
{
	int n, k;							//n = 참가하는 학생 수, k = 한 방에 배정할 수 있는 최대 인원 수
	int arr[2][7] = { 0, };				//arr[성별][학년] : 성별과 학년에 맞는 학생 수
	int s, y;							//s = 성별, y = 학년
	int cnt = 0;						//필요한 방의 수

	cin >> n >> k;


	for (int i = 0; i < n; i++)
	{
		cin >> s >> y;

		arr[s][y]++;					//입력한 성별과 학년에 맞는 학생 수를 1 증가
	}

	for (int i = 0; i <= 1; i++)
	{
		for (int j = 1; j <= 6; j++)
		{
			cnt += (arr[i][j] + k - 1) / k;	//각 arr[i][j]마다 (k-1)을 더해야 방의 개수가 맞는다.
		}
	}

	cout << cnt << endl;

	return 0;
}