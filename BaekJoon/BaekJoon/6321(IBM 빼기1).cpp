#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;											//컴퓨터의 개수
	string com;										//컴퓨터 이름
	cin >> n;

	for (int i = 1; i <= n; i++)						//입력n을 위한 반복문
	{
		cin >> com;

		cout << "String #" << i << endl;

		for (int j = 0; j < com.length(); j++)		//입력한 문자열 com의 문자 하나 당 확인
		{
			if (com[j] == 'Z')						//만약 문자 Z가 입력되면
				cout << 'A';						//A로 출력
			else									//나머지 알파벳의 경우
				cout << (char)(com[j] + 1);			//다음 알파벳을 출력
		}
		cout << endl << endl;
	}
	return 0;
}