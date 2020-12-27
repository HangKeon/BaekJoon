#include <iostream>
#include <string>
using namespace std;

int main()
{
	//char s[1000001];							//입력할 문자열
	string s;							//입력할 문자열	
	int cnt = 1;						//단어의 개수 -> 공백의 개수에 따라 개수가 1씩 증가하므로 처음은 1로 두어야 한다.

										//cin.getline(s,1000001);
	getline(cin, s);					//띄어쓰기까지 입력

	if (s[0] == ' ')					//만약 제일 앞이 공백인 경우
		cnt = 0;						//cnt 를 0으로 만들기

	for (int i = 0; i < s.length(); i++)	//공백이 나오는 경우 cnt를 1씩 증가
		if (s[i] == ' ')
			cnt++;

	if (s[s.length() - 1] == ' ')		//만약 제일 마지막이 공백인 경우
		cnt--;							//구했던 cnt에서 1을 감소

	cout << cnt << endl;


	return 0;
}