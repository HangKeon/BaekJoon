#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n;								//자연수의 개수
	int a;								//입력하는 값
	int sum = 2e9;						//가장 작은 차이의 합
	int temp = 0;						//차이의 합을 임시 저장
	int ans;							//sum에 저장되는 v의 값
	int arr[20001];						//arr[n] : 0~n번지까지의 v의 합을 저장
	vector<int> v;						//입력하는 값을 저장

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a;

		v.push_back(a);
	}

	sort(v.begin(), v.end());			//작은 값을 출력위해서

	for (int i = 0; i < n; i++)
	{
		if (i == 0)						//제일 처음 값
			arr[i] = v[i];
		else							//나머지는 구간합(prefis sum)
			arr[i] = arr[i - 1] + v[i];	//이중 for문을 사용하지 않아도 된다!
	}

	for (int i = 0; i < n; i++)
	{
		temp = v[i] * i - arr[i - 1] + (arr[n - 1] - arr[i]) - v[i] * (n - 1 - i);

		if (sum > temp)
		{
			sum = temp;
			ans = v[i];
		}
	}

	cout << ans << endl;

	return 0;
}