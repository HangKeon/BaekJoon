#include <iostream>
using namespace std;

int main()
{
	int n, k;							//n = 학생 수, k = 한 방에 배정할 수 있는 최대 인원 수
	int arr[2][7] = { 0, };				//arr[성별][학년] : 성별과 학년에 맞는 학생 수
	int s, y;							//s = 성별, y = 학년
	int cnt = 0;						//필요한 최소 방의 수

	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		cin >> s >> y;

		arr[s][y]++;					//성별과 학년에 맞는 학생 수를 1 증가
	}

	cnt += (arr[0][1] + arr[0][2] + arr[1][1] + arr[1][2] + k - 1) / k;		//1~2학년들의 방의 수

	for (int i = 0; i <= 1; i++)
	{
		for (int j = 3; j < 6; j += 2)										//3~4학년, 5~6학년을 각각 성별에 맞게 더하기 위해 2씩 증가
		{
			cnt += (arr[i][j] + arr[i][j+1] + k - 1) / k;
		}
	}

	cout << cnt << endl;

	return 0;
}