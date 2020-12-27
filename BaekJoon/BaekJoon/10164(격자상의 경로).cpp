#include <iostream>
using namespace std;

int factorial(int n)	//팩토리얼을 구하는 함수
{
	int result = 1;						//팩토리얼의 결과를 저장하는 변수

	for (int i = n; i > 1; i--)
		result *= i;

	return result;
}

int main()
{
	int n, m, k;						//n : 행의 수, m : 열의 수, k : o가 표시된 칸의 번호
	int result;							//경로의 수
	int r1, r2;

	cin >> n >> m >> k;

	if (k != 0)							//o가 있는 경우
	{
		if (k%m == 0)					//만약 o가 제일 오른쪽에 있다면
		{
			r1 = factorial(m - 1 + k % n);
			r2 = factorial(m - 1)*factorial(k%n);

			result = r1 / r2;
		}
		else							//일반적인 경우
		{
			r1 = factorial(k%m - 1 + k / m) / (factorial(k%m - 1)*factorial(k / m));
			r2 = factorial(m + n - 1 - k % m - k / m) / (factorial(m - k % m)*factorial(n - 1 - k / m));

			result = r1 * r2;
		}
	}
	else								//o가 없는 경우
		result = factorial(m + n - 2) / (factorial(m - 1)*factorial(n - 1));
	
	cout << result << endl;


	return 0;
}