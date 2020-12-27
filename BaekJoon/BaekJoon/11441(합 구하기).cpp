#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(0);

	int n;							//자연수의 개수
	int m;							//구간의 개수
	int add[100001] = { 0, };		//add[n] : arr[1] ~ arr[n]의 누적 합
	int a, b;						//a ~ b의 범위 -> 구간의 합을 구하기 위한 범위

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> a;

		add[i] = add[i - 1] + a;
	}

	cin >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;

		cout << add[b] - add[a - 1] << "\n";
	}

	return 0;
}