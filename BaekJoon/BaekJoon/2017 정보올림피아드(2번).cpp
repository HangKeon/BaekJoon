#include <iostream>
using namespace std;

int main()
{
	int N, num = 1;														//몇 번째에 위치하는지 알아볼 값
	cout << "숫자를 입력하세요 : ";										//num은 몇 번째 줄인지를 나타냄
	cin >> N;

	while (num++)
	{
		if (N == 8 * num + 1)											//1번째
		{
			cout << "1번째" << endl;
			break;
		}
		if (N == 8 * num - 6 || N == 8 * num)							//2번째 
		{
			cout << "2번째" << endl;
			break;
		}
		if (N == 4 * num - 1)											//3번째
		{
			cout << "3번째" << endl;
			break;
		}
		if (N == 8 * num - 4 || N == 8 * num - 2)						//4번째
		{
			cout << "4번째" << endl;
			break;
		}
		if (N == 8 * num - 3)											//5번째
		{
			cout << "5번째" << endl;
			break;
		}
	}

	return 0;
}

//하