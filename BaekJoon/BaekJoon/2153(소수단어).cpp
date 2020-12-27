#include <iostream>
using namespace std;

int main()
{
	char ch[20];												//단어를 20자 이내로 입력하기 때문.
	int sum = 0;												//입력한 문자열의 숫자 합
	bool check = 0;												//우선은 거짓으로 선언.


	while (1)
	{
		cin >> ch;

		if (strlen(ch) <= 20)									//입력하는 문자열의 길이가 20보다 같거나 작은 경우
		{
			for (int i = 0; i < strlen(ch); i++)
			{
				if (ch[i] >= 'A' && ch[i] <= 'Z')				//ch가 대문자인 경우
					sum += (int)ch[i] - 38;
				else if (ch[i] >= 'a' && ch[i] <= 'z')			//ch가 소문자인 경우
					sum += (int)ch[i] - 96;
			}

			for (int i = 2; i <= sum; i++)
			{
				if (i < sum && sum%i == 0)						//i<sum 이면서 소수가 아닌 경우
					break;

				if (i == sum && sum%i == 0)						//i=sum 이면서 sum을 i로 나눠었을 때의 나머지가 0인 경우! -> 즉, 자기 자신으로 나누어지는 경우!
					check = 1;
			}

			if (check || sum == 2)								//만약 check가 true 이거나 sum=2라면
				cout << "It is a prime word!" << endl;
			else												//그 이외에는
				cout << "It is not a prime word!" << endl;

			return 0;											//while문에서 나가기 위한 코드 -> 조건 충족 시 while문 밖으로 나감.
		}
		else
		{
			//입력하는 문자열의 크기가 20보다 큰 경우
		}
		cout << "다시 입력하세요 : ";

	}

	return 0;
}

//중상