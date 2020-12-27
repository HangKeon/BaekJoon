#include <iostream>
using namespace std;

int main()
{
	int n, k, s, y;						//n = 수학여행에 참가하는 학생 수, k = 한 방에 배정할 수 있는 최대 인원수, s = 성별, y = 학년
	double arr[2][7] = { 0, };			//arr[성별][학년] -> 학년의 경우 1~6학년이므로 7로 선언!
	double sum[5] = { 0, };				//같은 방으로 배정될 수 있는 학생들의 합
	int cnt = 0;

	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		cin >> s >> y;

		arr[s][y]++;					//언급된 성별 & 학년에 1 증가

	}

	for (int i = 0; i <= 1; i++)		//3~6학년의 방의 수를 구하는 식
	{
		for (int j = 3; j <= 5; j += 2)
		{
			cnt += (arr[i][j] + arr[i][j + 1] + k - 1) / k;
		}
	}

	cnt += (arr[0][1] + arr[0][2] + arr[1][1] + arr[1][2] + k - 1) / k;		//1~2학년의 방의 수를 구하는 식

	cout << cnt << endl;


	return 0;
}