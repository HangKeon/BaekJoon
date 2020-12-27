#include <iostream>
using namespace std;

int main()
{
	int n;							//도시의 개수
	long long road[100001];			//두 도시를 연결하는 도로의 길이 저장
	long long oil[100001];			//도시당 주유소 리터 가격
	long long d[100001] = { 0, };	//oil * road
	int min;						//최소 기름값

	cin >> n;

	for (int i = 0; i < n - 1; i++)
	{
		cin >> road[i];
	}

	for (int i = 0; i < n; i++)
	{
		cin >> oil[i];
	}

	d[0] = oil[0] * road[0];		//최초의 도시에서 무조건 기름을 채워야 하므로 road[0]만큼만 우선 채운다.

	min = oil[0];

	for (int i = 1; i < n; i++)
	{
		if (oil[i] < min)						//만약 oil이 min보다 작으면
			min = oil[i];						//min에 oil을 대입

		d[i] = d[i - 1] + min * road[i];		//d[i] = (이전 도시에서 채운 기름 가격) + (최소 기름값 min과 road[i]의 곱) 
	}

	cout << d[n - 1] << endl;


	return 0;
}