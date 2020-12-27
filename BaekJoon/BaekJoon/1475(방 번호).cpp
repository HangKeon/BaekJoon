#include <iostream>
using namespace std;

int main()
{
	int n;								//방 번호
	int ans;							//필요한 세트 개수 최소값
	int num[10] = { 0, };				//사용한 숫자의 개수
	int max = 0;						//사용된 숫자글 중 가장 많이 사용된 수의 개수를 저장
	int tmp;							//임시로 (num[6] + num[9] + 1)/2를 저장

	cin >> n;

	if (n == 0)								//n이 0인경우
		ans = 1;
	else
	{
		while (n)
		{
			num[n % 10]++;					//n의 각 자리를 나누어 저장
			n /= 10;						//사용된 n의 일의 자리는 제거
		}

		for (int i = 0; i < 10; i++)			//가장 많이 사용된 숫자의 개수를 구하기 위한 것 -> 6, 9는 제외
		{
			if (i != 6 && i != 9)
			{
				if (max < num[i])
					max = num[i];
			}
		}

		tmp = (num[6] + num[9] + 1) / 2;

		if (tmp < max)						//사용한 세트의 최솟값을 구하기
			ans = max;
		else
			ans = tmp;
	}
	cout << ans << endl;

	return 0;
}