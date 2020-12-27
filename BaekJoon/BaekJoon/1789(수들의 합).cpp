#include <iostream>
using namespace std;

int main()
{
	long long int s;						//서로 다른 n개의 자연수의 합
	long long int n = 0;					//s를 구하기 위한 자연수들의 개수
	long long int i = 0;					//반복문을 사용하기 위한 인덱스값
	int cnt = 0;							//S가 되기 위한 자연수의 개수

	cin >> s;

	while (1)
	{
		i++;
		n += i;
		cnt++;

		if (n > s)
		{
			cnt--;
			break;
		}
	}

	cout << cnt << endl;
	
	/*long long int k=1;					//4,294,967,295를 구하기 위한 식

	for (int j = 1; j <= 32; j++)
	{
		k *= 2;
	}
	cout << k << endl;*/

	return 0;
}