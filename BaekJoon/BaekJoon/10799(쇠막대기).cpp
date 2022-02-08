#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	string s;						//입력하는 문자열
	stack<char> c;					//'('을 저장하는 스택
	int cnt = 0;					//잘려진 쇠막대기 조각의 총 개수

	cin >> s;

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '(')			//'('인 경우 스택에 저장
			c.push(s[i]);
		else						//')'인 경우
		{
			c.pop();				//스택에서 제거

			if (s[i - 1] == '(')	//레이저인 경우
				cnt += c.size();	//남아있는 '(' 갯수만큼 더한다 -> 왜냐하면 이게 쇠막대기의 갯수이므로
			else					//막대기의 끝일 경우 -> ')'
				cnt++;
		}			
	}

	cout << cnt << endl;

	return 0;
}