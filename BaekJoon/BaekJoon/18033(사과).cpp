#include <iostream>
using namespace std;

int main()
{
	int N;								//학교의 수
	int student = 0, apple = 0;			//학생 수, 사과개수 -> 초기화
	int sum = 0;						//남은 사과 총 개수

	cin >> N;

	for (int i = 0; i < N; i++)			//N만큼 입력을 반복
	{
		cin >> student >> apple;
		sum += apple % student;			//각 학교마다 남은 사과 개수를 더함.
	}

	cout << sum << endl;

	return 0;
}

//하