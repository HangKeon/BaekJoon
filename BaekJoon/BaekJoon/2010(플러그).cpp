#include <iostream>
using namespace std;

int main()
{
	int n, value;							//n = 멀티탭 개수, value = 각 멀티탭의 플러그 개수
	int sum = 0;							//멀티탭 개수의 합

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> value;
		sum += value;
	}
	sum -= n - 1;							 //멀티탭을 연결하느라 사용된 플러그 수(n-1)을 빼기

	cout << sum << endl;

	return 0;
}