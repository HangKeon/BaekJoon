#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;						//전체 용액의 수
	int arr[100001];			//용액의 특성값을 저장하는 배열, 오름차순 입력
	int result = 2000000000;	//두 용액을 합한 값의 최솟값을 저장


	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);

	int a = 0, b = n - 1;		//a : arr의 시작 인덱스, b : arr의 끝 인덱스
	int temp_a, temp_b;			//result의 값이 바뀔 때 저장할 a,b

	while (a < b)
	{
		if (result >= abs(arr[a] + arr[b]))	//만약 result 절댓값이 arr[a]+arr[b]의 절댓값보다 더 큰 경우
		{
			result = abs(arr[a] + arr[b]);			//즉, 0에서 더 멀리 떨어져있는 경우
			temp_a = a;
			temp_b = b;
		}

		if (arr[a] + arr[b] < 0)
			a++;
		else if (arr[a] + arr[b] > 0)
			b--;
		else
			break;
	}

	cout << arr[temp_a] << ' ' << arr[temp_b] << endl;


	return 0;
}