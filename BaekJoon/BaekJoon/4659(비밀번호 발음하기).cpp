#include <iostream>
#include <string>
using namespace std;

int main()
{
	char odd[] = { 'a','e','i','o','u' };			//모음을 나타내는 배열
	string s;										//입력할 문자열

	while (1)
	{
		int first_condition = 0;					//1번 조건이 참임을 표현하기 위한 변수
		int t = 1;									//1,2,3조건이 모두 참인 경우
		int odd_cnt = 0;									//모음이 연속으로 나오는 경우 세는 변수
		int even_cnt = 0;									//자음이 연속으로 나오는 경우 세는 변수

		cin >> s;

		if (s == "end")								//입력한 문자열s가 end인 경우
			break;

		for (int i = 0; i < s.length(); i++)			//입력한 문자열s와 모음odd를 비교
			for (int j = 0; j < 5; j++)
				if (s[i] == odd[j])					//만약 s가 모음을 갖고 있다면 -> 1번 조건
					first_condition = 1;

		if (!first_condition)						//1번 조건에 만족하지 않다면
		{
			cout << "<" << s << ">는 사용할 수 없습니다." << endl;
			t = 0;
		}
		else
		{
			for (int i = 0; i < s.length(); i++)
			{
				int second_condition = 0;							//2번 조건을 위한 변수


				if (s[i + 1] == s[i] && s[i] != 'e'&&s[i] != 'o')	//3번 조건이 성립하지 않을 때
				{
					cout << "<" << s << ">는 사용할 수 없습니다." << endl;
					t = 0;
					break;
				}

				for (int j = 0; j < 5; j++)							//2번 조건을 위해 모음이 오는 경우를 확인
					if (s[i] == odd[j])
						second_condition = 1;

				if (second_condition)								//모음이 연속으로 오는 경우
				{
					odd_cnt++;
					even_cnt = 0;
				}
				else												//자음이 연속으로 오는 경우
				{
					odd_cnt = 0;
					even_cnt++;
				}

				if (odd_cnt == 3 || even_cnt == 3)					//2번 조건
				{
					cout << "<" << s << ">는 사용할 수 없습니다." << endl;
					t = 0;
					break;
				}
			}
		}

		if (t)														//1,2,3 모든 조건이 다 성립하는 경우
			cout << "<" << s << ">는 사용가능 합니다." << endl;
	}

	return 0;
}