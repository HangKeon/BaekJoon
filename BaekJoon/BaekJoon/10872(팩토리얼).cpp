#include <iostream>
using namespace std;

int fac(int n)				//팩토리얼 재귀함수
{
	if (n <= 1)
		return 1;

	return n * fac(n - 1);
}

int main()
{
	int n;					//팩토리얼 시작값
	int ans;				//팩토리얼 함수를 저장하는 변수

	cin >> n;

	ans = fac(n);

	cout << ans << endl;

	return 0;
}