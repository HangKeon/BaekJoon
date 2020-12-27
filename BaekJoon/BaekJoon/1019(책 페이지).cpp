#include <iostream>
using namespace std;

int main()
{
	int N;											//책 페이지 수
	int arr[10] = { 0, };							//0~9 개수
	int val[5] = { 0, };							//각 자리수의 값을 저장할 배열
	int sum = 0;

	cout << "N : ";
	cin >> N;

	while (N<1 || N >= 10000)
	{
		cout << "N은 1 이상 10000미만의 값이어야 한다. 다시 입력하세요 : ";
		cin >> N;
	}
	

	for (int i = 1; i <= N; i++)
	{
		if (i<10)								//한 자리 수
		{
			arr[i] += 1;
		}
		else if (i >= 10 && i<100)				//두 자리 수
		{
			val[1] = i % 10;					//일의 자리
			val[2] = i / 10;					//십의 자리
			arr[val[1]] += 1;					//val[1]에 저장된 값의 개수
			arr[val[2]] += 1;					//val[2]에 저장된 값의 개수
		}
		else if (i >= 100 && i<1000)			//세 자리 수
		{
			val[1] = i % 10;					//일의 자리
			val[2] = (i % 100) / 10;				//십의 자리
			val[3] = i / 100;					//백의 자리
			arr[val[1]] += 1;
			arr[val[2]] += 1;
			arr[val[3]] += 1;

		}
		else if (i >= 1000 && i<10000)					//네 자리 수
		{
			val[1] = i % 10;							//일의 자리
			val[2] = (i % 100) / 10;						//십의 자리
			val[3] = (i % 1000) / 1000;					//백의 자리
			val[4] = i / 1000;							//천의 자리
			arr[val[1]] += 1;
			arr[val[2]] += 1;
			arr[val[3]] += 1;
			arr[val[4]] += 1;
		}
	}

	for (int i = 0; i <= 9; i++)
	{
		cout << i << " 개수 : " << arr[i] << endl;
		//sum += arr[i];				-->이건 그냥 디버깅하느라 쓴거.

	}
	//cout << sum << endl;				-->이건 그냥 디버깅하느라 쓴거.

	return 0;
}
//중