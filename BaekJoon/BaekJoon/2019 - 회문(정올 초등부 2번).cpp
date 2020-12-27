#include <iostream>
#include <string>
using namespace std;

int main()
{
	int t;								//문자열 개수
	char s[100001], q[100001];			//s = 문자열을 입력받을 배열, q = 유사회문을 구할 때 사용할 배열
	int cnt[31];						//각 문자열의 수(0,1,2)를 저장할 배열

	cin >> t;

	for (int k = 0; k < t; k++)
	{
		int i;

		cin >> s;

		int n = strlen(s);									//입력한 문자의 개수

		for (i = 0; i < n; i++)
			if (s[i] != s[n - i - 1])						//만약 s[i]와 s[n-i-1]이 다른 문자일 경우 - > 회문이 아닐 경우
				break;

		if (i == n)											//위의 if문을 모두 통과한 경우 -> 즉, 회문인 경우
		{
			//cout << '0' << endl;
			cnt[k] = 0;
			continue;
		}

		int pv = i, c = 0;									//pv = 위에서 s[i] != s[n-1-i]인 i값을 저장, c = q의 인덱스

		for (i = 0; i < n; i++)								//i와 pv를 비교 -> 왼쪽 값을 건너뛰고 q에 저장하는 경우
			if (i != pv)
				q[c++] = s[i];

		for (i = 0; i < c; i++)								//왼쪽 값을 건너뛰고 저장한 q가 유사회문인지 확인
			if (q[i] != q[c - 1 - i])
				break;

		if (i == c)											//유사회문인 경우
		{
			//cout << '1' << endl;
			cnt[k] = 1;
			continue;
		}

		c = 0;												//왼쪽을 건너뛴 값이 유사회문이 아닌 경우 q를 다시 저장해야 하므로 c를 0으로 초기화

		for (i = 0; i < n; i++)								//i와 (n-1)ipv를 비교 -> 오른쪽 값을 건너 뛰고 q에 저장하는 경우
			if (i != n - 1 - pv)
				q[c++] = s[i];

		for (i = 0; i < c; i++)								//오른쪽 값을 건너뛰고 저장한 q가 유사회문인지 확인
			if (q[i]!=q[c - 1 - i])
				break;

		if (i == c)											//유사회문인 경우
		{
			//cout << '1' << endl;
			cnt[k] = 1;
			continue;
		}

		//cout << '2' << endl;								//나머지 -> 회문, 유사회문 x
		cnt[k] = 2;
	}

	for (int k = 0; k < t; k++)
		cout << cnt[k] << endl;

	return 0;
}