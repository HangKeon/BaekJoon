#include <iostream>
#include <algorithm>
using namespace std;
//이 코드는 시간초과남

int gun[100001];				//사대의 x좌표
int x[100001];					//동물의 x좌표
int y[100001];					//동물의 y좌표

int main()
{
	int m, n, l;					//m : 사대의 수, n : 동물의 수, l : 사정거리
	int cnt = 0;					//잡을 수 있는 동물의 수

	cin >> m >> n >> l;

	for (int i = 0; i < m; i++)
		cin >> gun[i];

	//sort(gun, gun + n);				//gun을 오름차순으로 배열

	for (int i = 0; i < n; i++)
	{
		cin >> x[i] >> y[i];
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (x[j] < 0 || y[j] < 0)	//이미 개수를 센 동물은 제외하기 위한 조건
				continue;

			int d;						//사대의 위치와 동물의 위치 간의 거리

			if (gun[i] >= x[j])
				d = gun[i] - x[j] + y[j];
			else
				d = x[j] - gun[i] + y[j];

			if (d <= l)					//이미 i번째 사대에서 성립한 경우는 중복을 막기 위해 x,y를 음수 대입
			{
				x[j] = -1;
				y[j] = -1;
				cnt++;
			}
		}
	}

	cout << cnt << endl;
	
	return 0;
}