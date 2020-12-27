#include <iostream>
using namespace std;

int main()
{
	int n;							//입력할 10개의 숫자
	int rest[42] = { 0, };			//나머지를 저장할 배열
	int cnt = 0;					//서로 다른 나머지의 개수를 세는 변수

	for (int i = 0; i < 10; i++)
	{
		cin >> n;

		rest[n % 42] = 1;
	}
		
	for (int i = 0; i < 42; i++)
	{
		if (rest[i] != 0)
			cnt++;
	}

	cout << cnt << endl;

	return 0;
}