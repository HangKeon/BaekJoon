#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
//실패 코드

int arr[51][51];						//직접 친구 :1, 경유해서 친구 : 2, 친구x : 0 

int main()
{
	int n;								//사람 수 
	int cnt = 0;						//가장 유명한 사람의 2-친구 수
	int temp;							//각 사람마다 2-친구 수
	string s[51];						//Y : 친구o, N : 친구x

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> s[i];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (i == j)					//자기 자신은 친구가 될 수 없다고 문제에 나옴.
				continue;

			if (s[i][j] == 'Y')			//i,j가 친구인 경우
				arr[i][j] = 1;
			else						//i,j가 친구가 아닌 경우
				arr[i][j] = 1e9;
		}
		

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
			{
				if (i == j || j == k || k == i)		//자기 자신은 살펴볼 필요가 없다.
					continue;
				 
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
			}

	for (int i = 1; i <= n; i++)
	{
		temp = 0;

		for (int j = 1; j <= n; j++)
		{
			if (i == j)					//자기 자신은 친구가 될 수 없다.
				continue;
			else if (arr[i][j] <= 2)	//친구인 경우(1,2)
				temp++;
		}

		cnt = max(cnt, temp);
	}

	cout << cnt << endl;

	return 0;
}