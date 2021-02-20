#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n;                        //저울추의 개수

	cin >> n;

	vector<int> v(n + 1);               //저울추의 무게
	vector<int> sum(n + 1);            //저울추의 무게의 누적합

	for (int i = 1; i <= n; i++)
		cin >> v[i];

	sort(v.begin(), v.end());         //오름차순 정렬

	if (v[1] > 1)                  //맨 처음값이 1보다 크다면 1을 출력
	{
		cout << 1 << endl;

		return 0;
	}

	for (int i = 1; i <= n; i++)
	{
		sum[i] = v[i] + sum[i - 1];

		if (sum[i - 1] + 1 < v[i])      //(i-1)까지의 누적합+1 < v[i]인 경우
		{
			cout << sum[i - 1] + 1 << endl;
			return 0;
		}
	}

	cout << sum[n] + 1 << endl;         //(모든 누적합+1)


	return 0;
}