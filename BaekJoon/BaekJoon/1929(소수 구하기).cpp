#include <iostream>
#include <vector>
using namespace std;

//int arr[1000001];

int main()
{
	int m, n;

	cin >> m >> n;

	vector<int> arr(n + 1);

	arr[0] = 0;
	arr[1] = 0;

	for (int i = 2; i <= n; i++)			//원래 넣으려는 값보다 2은 인덱스에 넣어준다.
		arr[i] = i;

	for (int i = 2; i <= n; i++)
	{
		if (arr[i] == 0)
			continue;

		for (int j = 2 * i; j <= n; j += i)
		{
			arr[j] = 0;
		}
	}

	for (int i = m; i <= n; i++)
	{
		if (arr[i] != 0)
			cout << i << endl;
	}

	return 0;
}