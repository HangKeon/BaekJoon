#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;								//로프의 개수
	long long sum = 0;					//물체의 최대 중량
	long long arr[100001];				//로프가 버틸 수 있는 무게

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);

	for (int i = 0; i < n; i++)
	{
		sum = max(sum, arr[i] * (n - i));
	}

	cout << sum << endl;

	return 0;
}