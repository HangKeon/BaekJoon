#include <iostream>
using namespace std;
#include <algorithm>

int main()
{
	int page[11] = { 0, };				//페이지에 사용된 수의 개수를 저장할 배열
	int n;								//책의 페이지

	cin >> n;
	
	for (int i = 1; i <= n; i++)			//책 페이지는 1쪽부터 시작하므로 i도 1부터 시작
	{
		int num = i;

		while (num != 0)
		{
			page[num % 10]++;			//나온 숫자를 저장
			num /= 10;

			if (num == 0)				//탈출조건
				break;
		}
	}

	for (int i = 0; i < 9; i++)
	{
		cout << i << " 개수 : " << page[i] << endl;
	}

	return 0;
}