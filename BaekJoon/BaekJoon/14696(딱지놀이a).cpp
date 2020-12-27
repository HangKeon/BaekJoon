#include <iostream>
using namespace std;

int main()
{
	int n;								//그림의 총 개수
	int tmp;							//그림 모양을 입력받는 변수
	int a[5] = { 0, };					//딱지 그림을 저장할 배열(1~4)

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> tmp;

		a[tmp]++;						//입력된 딱지의 그림 모양(tmp)를 배열a에 갯수를 저장!
	}

	for (int i = 4; i >= 1; i--)
		cout << a[i] << ' ';

	cout << endl;


	return 0;
}