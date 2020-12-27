#include <iostream>
using namespace std;

int main()
{
	int n;								//막대기 개수
	int stick[100001];					//막대의 높이
	int cnt = 0;						//가장 오른쪽에 있는 막대보다 긴 막대의 개수

	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> stick[i];

	for (int i = 1; i < n; i++)
	{
		if (stick[i] > stick[n])
			cnt++;
	}

	cout << cnt << endl;

	return 0;
}