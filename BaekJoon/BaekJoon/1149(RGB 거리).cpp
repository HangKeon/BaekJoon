#include <iostream>
#include <algorithm>						//min 함수를 쓰기 위해 사용.
using namespace std;

int main()
{
	int n;									//집의 수
	int arr[1000][3] = { 0, };				//비용

	cin >> n;

	for (int i = 0; i < n; i++)				//입력
		for (int j = 0; j < 3; j++)
			cin >> arr[i][j];

	for (int i = 1; i < n; i++)				//나올 수 있는 모든 경우를 다 비교
	{
		arr[i][0] += min(arr[i - 1][1], arr[i - 1][2]);
		arr[i][1] += min(arr[i - 1][0], arr[i - 1][2]);
		arr[i][2] += min(arr[i - 1][0], arr[i - 1][1]);
	}

	cout << min(arr[n - 1][0], min(arr[n - 1][1], arr[n - 1][2])) << endl;

	return 0;
}