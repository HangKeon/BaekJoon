#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n, k;					//n : 전체 수의 개수, k : 선택한 수의 개수
	int sum = 0;				//arr의 k개의 합
	int arr[5001];

	cin >> n >> k;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n, greater<int>());

	for (int i = 0; i < k; i++)
		sum += arr[i] - i;

	cout << sum << endl;

	return 0;
}