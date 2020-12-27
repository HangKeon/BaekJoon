#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s, bomb;					//s : 입력할 문자열, bomb : 폭발 문자열
	char result[1000001];			//문자열 s를 하나씩 대입하면서 bomb와 같은 것을 찾을 배열
	int len;						//bomb의 길이를 저장할 변수
	int idx = 0;					//result의 인덱스

	cin >> s >> bomb;


	for (int i = 0; i < s.length(); i++)
	{
		result[idx] = s[i];		//result에 s의 문자를 하나씩 대입!

		len = bomb.length();
		int temp = len - 1;			//bomb의 인덱스로 뒤에서 부터 읽는다 -> len-1을 대입해야 한다
		int check = 0;				//check = 1인 경우, result의 bomb와 같은 부분을 삭제하고 idx를 len만큼 내린다.

		if (s[i] == bomb[temp])			//s[i]와 bomb[temp]가 같다면
		{
			for (int j = idx; j > idx - len; i--)
			{
				if (result[idx] == bomb[temp])
				{
					check = 1;
					temp--;
				}
			}

			if (check == 1)
				idx -= len;			//bomb와 같은 부분을 삭제하고 그 부분부터 다시 입력!
			
		}



		idx++;
	}

			/*
	if (idx == 0)					//result에 저장된 문자가 없는 경우
	{
		cout << "FRULA" << endl;
		return 0;
	}

	for(int i=0;i<idx;i++)
		cout << result[i];

	cout << endl;*/

	return 0;
}