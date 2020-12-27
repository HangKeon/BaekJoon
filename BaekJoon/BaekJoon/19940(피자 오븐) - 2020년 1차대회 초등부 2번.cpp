#include <iostream>
using namespace std;

int main()
{
	int t;							//테스트 케이스 개수
	int n;							//설정해야 하는 시간
	
	
	cin >> t;

	while (t--)
	{
		int arr[5] = { 0, };			//ADDH(+60), ADDT(+10), MINT(-10), ADDO(+1), MINO(-1)

		cin >> n;

		arr[0] += n / 60;			//ADDH의 개수를 구함

		n %= 60;

		if (n > 35)					//ADDH 1번하고 MINT, MINO를 쓰는게 횟수가 적다
		{
			arr[0]++;				//ADDH 1 증가

			arr[2] = 6 - (n + 5) / 10;		//MINT 개수를 구함 -> x5까지는 큰 값에서 빼는게 낫다
			n %= 10;

			if (n >= 5)				//MINO를 사용하는게 횟수가 더 적다.
			{				
				arr[4] += 10 - n;	//MINO를 (10-n) 만큼 증가
			}
			else					//if(n <= 5) -> ADDO를 사용하는게 횟수가 더 적다
			{
				arr[3] += n;		//ADDO를 n만큼 증가
			}
		}
		else						//if(n<=35) -> ADDHT 1번하고 ADDO를 쓰는게 훨씬 낫다
		{
			arr[1] = n / 10;		//ADDT의 갯수를 구함

			n %= 10;

			if (n > 5)				//한 자리 수일때 n>5이면 ADDT를 1번 사용하고 MINO를 사용하는게 횟수가 더 적다.
			{
				arr[1] ++;			//ADDT를 1 증가

				arr[4] += 10 - n;	//MINO를 (10 - n)만큼 증가
			}
			else					//한 자리 수일때 n<=5이면 ADDO를 사용하는게 횟수가 더 적다.
			{
				arr[3] += n;		//ADDO를 n만큼 증가
			}
		}


		for (int i = 0; i < 5; i++)
			cout << arr[i] << ' ';

		cout << endl;
	}

	return 0;
}