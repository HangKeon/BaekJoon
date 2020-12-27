#include <iostream>
using namespace std;

int main()
{
	int n;							//레벨 수
	int v[101];						//레벨 별 얻는 점수를 저장
	int cnt = 0;

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> v[i];

	for (int i = n - 2; i >= 0; i--)
	{
		if (v[i] >= v[i + 1])
		{
			int dis = v[i] - v[i + 1] + 1;		//(v[i]와 v[i+1]의 차 + 1) 한 만큼을 빼주어야 한다.
			v[i] = v[i + 1] - 1;
			cnt += dis;
		}
	}

	cout << cnt << endl;

	return 0;
}