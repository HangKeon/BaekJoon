#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;						//카드의 개수
	int m;						//딜러가 외치는 숫자
	int ans = 0;				//3가지 합 중 가장 m에 가까운 값
	int temp;					//임시로 3가지 합을 저장할 변수
	int arr[100001];			//카드
	int a, b, c;

	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < n - 2; i++)
	{
		for (int j = i + 1; j < n - 1; j++)
		{
			for (int k = j + 1; k < n; k++)
			{
				if (i == j || j == k || i == k)		//같은 값이 나오는 것을 방지
					continue;

				temp = arr[i] + arr[j] + arr[k];

				if (temp <= m)
					ans = max(ans, temp);
			}
		}
	}

	cout << ans << endl;

	return 0;
}