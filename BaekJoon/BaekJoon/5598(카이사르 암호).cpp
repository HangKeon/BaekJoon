#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;							//입력할 문자열

	cin >> s;

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] - 3 < 65)				//s[i]를 왼쪽으로 3칸 옮겼을 때 A(63)보다 작은 경우
			s[i] = s[i] + 23;
		else
			s[i] -= 3;					//나머지는 왼쪽으로 3칸 이동
	}

	cout << s << endl;

	return 0;
}