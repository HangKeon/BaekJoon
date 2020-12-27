#include <iostream>
using namespace std;

int main()
{
	int n;								//1~n 까지의 수 중 3,6,9를 찾기 위한 변수
	int arr[1000001];					//1~n까지의 수를 저장할 배열
	int cnt = 0;						//3,6,9의 개수를 세는 변수

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		arr[i] = i;

		int temp = arr[i];				//임시로 arr을 저장
		int len = 0;					//arr의 자리수를 세는 변수

		while (temp != 0)
		{
			temp /= 10;
			len++;
		}

		temp = arr[i];					//다시 temp에 arr을 저장

		for (int j = 0; j < len; j++)
		{
			if (temp % 10 == 3 || temp % 10 == 6 || temp % 10 == 9)
				cnt++;

			temp /= 10;

		}
	}


	cout << cnt << endl;

	return 0;
}