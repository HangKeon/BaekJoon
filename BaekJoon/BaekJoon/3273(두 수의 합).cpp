#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;							//수열의 크기
	int x;							//구해야 하는 값
	int left, right;				//left : 인덱스 제일 왼쪽값, right : 인덱스 제일 오른쪽 값
	int cnt = 0;					//x값을 만족하는 수열의 갯수
	int sum;						//arr[left]+arr[right]
	int arr[100001];				//수열

	cin >> n;

	left = 0;
	right = n - 1;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
	
	cin >> x;

	sort(arr, arr + n);

	while (left < right)			//arr[left] == arr[right]인 경우 sum == x일 수 있다.
	{
		sum = arr[left] + arr[right];

		if (sum < x)
			left++;
		else if (sum > x)
			right--;
		else
		{
			cnt++;
			left++;
			right--;
		}
	}

	cout << cnt << endl;

	return 0;
}