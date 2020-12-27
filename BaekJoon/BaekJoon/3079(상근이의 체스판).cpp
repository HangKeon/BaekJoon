#include <iostream>
using namespace std;

int main()
{
	int R, C, A, B;					//R = 행, C = 열, A = 행의 높이인 문자의 개수, B = 열의 너비인 문자의 개수

	cin >> R >> C;
	cin >> A >> B;

	for (int i = 0; i < R*A; i++)
	{
		for (int j = 0; j < C*B; j++)
		{
			if ((i / A + j / B) % 2 == 0)
				cout << "X";
			else
				cout << ".";
		}
		cout << endl;
	}

	return 0;
}