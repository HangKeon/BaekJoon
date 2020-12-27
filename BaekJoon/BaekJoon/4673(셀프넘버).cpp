#include <iostream>
using namespace std;
#define N 10001

bool check[10001] = { 0, };							//셀프넘버가 아닌 값들을 true로 반영할 값

int SelfNum(int n)									//셀프 넘버가 아닌 값들을 찾는 함수
{
	int sum = n;									//합에다가 미리 n을 대입
	while (1)
	{
		if (n == 0)									//n=0인 경우 멈춤
			break;
		sum += n % 10;								//n의 나머지를 sum에 더한다.
		n /= 10;									//n을 10으로 나눈 값으로 대입
	}

	return sum;
}

int main()
{
	for (int i = 1; i <= N; i++)					//1~N까지의 범위
	{
		if (SelfNum(i) <= N)					//SelfNum의 값이 N보다 작거나 같은 경우
			check[SelfNum(i)] = 1;				//check의 값에 1을 대입 -> 참으로 만듬
	}

	for (int i = 1; i < N; i++)
		if (!check[i])							//만약 check가 false라면
			cout << i << "  ";					//출력

	return 0;
}