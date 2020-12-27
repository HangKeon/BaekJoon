#include <iostream>
using namespace std;

int main()
{
	for (int i = 4; i <= 1000; i++)			//4 ~ 1000 사이의 완전수를 구하기 위한 것
	{
		int sum = 0;						//자신을 제외한 약수의 합을 저장

		for (int j = 1; j <= i / 2; j++)		//i의 약수를 찾기 위한 것
		{
			if (i%j == 0)					//j가 i의 약수라면
				sum += j;
		}

		if (sum == i)							//완전수라면
			cout << sum << endl;
	}


	return 0;
}