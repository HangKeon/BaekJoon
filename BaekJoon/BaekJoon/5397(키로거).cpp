#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int n;									//테스트 케이스의 개수
	char s[1000001];						//입력하는 문자열
	char s2[1000001];						//<, >, - 사용 시 ans로부터 저장할 배열
	char ans[1000001];						//출력할 문자열

	cin >> n;

	while (n--)
	{
		int i = 0, j = 0, k = 0;					//i = s에 관한 인덱스, j = ans에 관한 인덱스, k = s2에 관한 인덱스

		cin >> s;

		int len = strlen(s);						//입력한 문자열s의 길이

		while (len--)								//문자열s를 전부 다 살펴보는 동안 실행
		{
			if (s[i] == '<')						//s가 '<' 인 경우
			{
				if (j > 0)							//커서 바로 앞에 글자가 존재한다면
					s2[k++] = ans[--j];

			}
			else if (s[i] == '>')					//s가 '>'인 경우
			{
				if (k > 0)							//커서 바로 앞에 글자가 존재한다면
					ans[j++] = s2[--k];

			}
			else if (s[i] == '-')					//s가 '-'인 경우
			{
				if (j > 0)							//커서 바로 앞에 글자가 존재한다면
					ans[--j] = 0;
			}
			else
			{
				ans[j++] = s[i];
			}

			i++;									//문자열s의 배열을 1씩 증가
		}

		while (k--)									//s2에 커서가 남아있는 경우
			ans[j++] = s2[k];						//s2에 남아 있는 값들을 ans 뒤에 대입

		ans[j] = 0;									//혹시라도 ans 마지막에 '\0'가 안 들어가는 것을 대비!

		cout <<ans<< endl;
	}



	return 0;
}