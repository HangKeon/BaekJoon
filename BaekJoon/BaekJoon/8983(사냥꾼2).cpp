#include <iostream>
#include <algorithm>
using namespace std;

int gun[100001];						//사대의 x좌표
pair<int, int> p[100001];				//동물의 좌표

int distance(int x, int a, int b)	//사대와 동물사이의 거리 -> |x-a|+b
{
	if (x > a)
		return (x - a + b);
	else
		return (a - x + b);
}

int main()
{
	int m, n, l;						//m : 사대의 수, n : 동물의 수, l : 사정거리
	//int idx = 0;						//x를 오름차순으로 정렬할 때의 인덱스로 사용
	int index = 0;						//gun의 인덱스로 사용
	int cnt = 0;						//잡을 수 있는 동물의 수

	cin >> m >> n >> l;

	for (int i = 0; i < m; i++)
		cin >> gun[i];

	for (int i = 0; i < n; i++)
		cin >> p[i].first >> p[i].second;

	sort(gun, gun + m);					//사대를 오름차순 정렬
	sort(p, p + n);						//동물의 위치도 

	for (int i = 0; i < n; i++)			//동물의 위치를 기준으로 살핀다.
	{
		while (index != m - 1 && gun[index + 1] < p[i].first)	//동물의 위치의 x값(x[i])보다 왼쪽에 있는 사대의 위치 중 가장 가까운 위치를 찾음.
			index++;									//그래서 gun[index+1]의 위치를 살펴봄.
	
		if (distance(gun[index], p[i].first, p[i].second) <= l)		//동물의 위치보다 왼쪽or 같은 x좌표의 사대를 비교
		{
			cnt++;
			continue;
		}

		if (index != m - 1)
		{
			if (distance(gun[index + 1], p[i].first, p[i].second) <= l)		//동물의 위치보다 (왼쪽+1)의 사대를 비교
			{
				cnt++;
				continue;
			}
		}
	}

	cout << cnt << endl;

	return 0;
}