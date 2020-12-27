#include <iostream>
using namespace std;

int main()
{
	int n;								//입력 개수
	int arr[51];						//비교할 숫자를 입력하는 배열
	int a, b;							//a : 곱하는 수, b : 더하는 수

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	if (n == 1)							//n이 1인 경우 다음 값으로 나올 수 있는 경우가 많다.
	{
		cout << 'A' << endl;
		return 0;
	}
	else if (n == 2)					//n이 2인 경우 공비만큼 곱해주면 된다
	{
		if (arr[0] == arr[1])			//입력한 두 값이 같다면 다음 값도 같다
			cout << arr[0] << endl;
		else							//입력한 두 값이 다르면 그 다음 값으로 나올 수 있는 경우가 많다.
			cout << 'A' << endl;

		return 0;
	}
	
	if (arr[1] == arr[0])				//분모가 0인 경우
		a = 0;
	else								//분모가 0이 아닌 경우
		a = (arr[2] - arr[1]) / (arr[1] - arr[0]);

	b = arr[1] - arr[0] * a;
	

	for (int i = 0; i < n - 1; i++)
	{
		if (arr[i + 1] != arr[i] * a + b)	//즉, a,b가 성립하지 않는 경우
		{
			cout << 'B' << endl;
			return 0;
		}

		arr[i + 2] = arr[i + 1] * a + b;

	}
	
	cout << arr[n] << endl;


	return 0;
}