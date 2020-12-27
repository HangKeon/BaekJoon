#include <iostream>
using namespace std;

int main()
{
	int a[51];
	int b[51];
	int n;							//배열에 저장되는 원소의 개수
	int s = 0;						//a,b의 합

	cin >> n;

	for (int i = 0; i < n - 1; i++)
	{
		cin >> a[i];
		cin >> b[i];
	}

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)	//a의 오름차순 -> 버블정렬
		{
			if (a[j] > a[j + 1])
			{
				int tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}

		for (int j = 0; j < n - 1 - i; j++)	//b의 내림차순 -> 버블정렬
		{
			if (b[j] < b[j + 1])
			{
				int tmp = b[j];
				b[j] = b[j + 1];
				b[j + 1] = tmp;
			}
		}
	}

	for (int i = 0; i < n; i++)
		s += a[i] * b[i];

	cout << s << endl;

	return 0;
}