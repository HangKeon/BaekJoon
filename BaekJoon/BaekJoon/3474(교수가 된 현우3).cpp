#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int t;							//입력할 줄의 수
	int n;							//입력할 값
	

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int two = 0, five = 0;			//two : 2의 개수를 저장, five : 5의 개수를 저장

		cin >> n;

		for (int j = 2; j <= n; j *= 2)
			two += n / j;

		for (int j = 5; j <= n; j *= 5)
			five += n / j;

		cout << min(two, five) << endl;
	}




	return 0;
}