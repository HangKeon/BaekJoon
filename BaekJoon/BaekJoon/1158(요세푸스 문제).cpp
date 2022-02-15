#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int n, k;					// n : 사람 수, k : 순서
	int temp;					//임시 변수
	queue<int> q;				//출력할 값을 담음

	cin >> n >> k;

	for (int i = 1; i <= n; i++)
		q.push(i);

	cout << '<';

	while (1)
	{
		for (int i = 0; i < k - 1; i++)		//k번째 사람을 찾기 위해 (k-1)번 넘김
		{
			temp = q.front();
			q.pop();
			q.push(temp);
		}

		cout << q.front();
		q.pop();

		if (!q.size())						//q에 아무도 없으면 탈출
			break;

		cout << ", ";
	}

	cout << '>';

	return 0;
}