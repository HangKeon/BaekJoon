#include <iostream>
using namespace std;

int main()
{
	int n, p;						//입력할 변수
	int arr[100];					//p로 나누었을 때 나머지가 저장될 변수 -> 순서대로 저장!
	int now;						//현재 값을 저장하는 변수
	int j = 0;

	cin >> n >> p;

	arr[j] = n;
	j++;

	now = n;

	while (1)
	{
		now = (now * n) % p;

		for (int i = 0; i < j; i++)
		{
			if (arr[i] == now)			//어디서 순환되는지 찾는 조건
			{
				cout << j - i << endl;
				return 0;
			}
		}

		arr[j] = now;					//현재 값(now)를 arr에 저장
		j++;
	}


	return 0;
}