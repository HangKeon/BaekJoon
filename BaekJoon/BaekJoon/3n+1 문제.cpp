#include <iostream>
#include <vector>
using namespace std;
#define MAX_VALUE 1000001

vector<int> v;

int count(long long int x)
{
	int cnt = 1;
	int temp = x;
	while (x != 1)
	{
		if (x % 2 == 0)
			x /= 2;
		else
			x = 3 * x + 1;

		if (x < MAX_VALUE && v[x] != 0)		//이미 계산한 적이 있는 값 -> 즉, dp의 메모라이제이션의 핵심부분!
		{
			v[temp] = v[x] + cnt;			//이미 계산했던 값(v[x])를 이용해 새로운 값(v[temp])의 값을 구한다.
			return v[temp];
		}

		cnt++;
	}

	v[temp] = cnt;
	return cnt;
}


int main()
{
	int cnt, i, j, max = -1, result;	//cnt = 사이클 길이, i,j = 시작 & 끝값, max = 최대값, result

	for (int i = 0; i < MAX_VALUE; i++)	//처음 모든 v값을 0으로 초기화
	{
		v.push_back(0);
	}

	cin >> i >> j;

	for (int n = i; n <= j; n++)			//i와 j 사이의 모든 값들의 최대 사이클 길이를 알아보기 위한 반복문
	{
		cnt = count(n);					//cnt에 count함수 대입

		if (max < cnt)					//만약 max < cnt 라면
		{
			max = cnt;					//max에 cnt 대입
			result = n;
		}
	}

	cout << i << " " << j << " " << max << endl;

	return 0;
}



//사실 이건 dp문제! 그렇기 때문에 나중에 다시 풀어보자!
/*int main()
{
	int n, num, i, j, max = -1, cnt;

	cin >> i >> j;

	for (int n = i; n <= j; n++)
	{
		cnt = 1;
		num = n;
		while (num != 1)
		{
			if (num % 2 == 0)
				num /= 2;
			else
				num = 3 * num + 1;
			cnt++;
		}

		if (max < cnt)
			max = cnt;
	}

	cout << i << ' ' << j << ' ' << max << endl;

	return 0;
}*/