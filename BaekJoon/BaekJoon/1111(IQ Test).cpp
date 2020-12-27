#include <iostream>
using namespace std;

int main()
{
	int N;						//첫째줄에 입력하는 숫자, 둘째 줄에 적을 숫자의 갯수를 의미. N<=50인 자연수
	//int *arr = new int[N];		//둘째 줄에 적는 숫자를 의미.	|arr|<100인 정수
	int *arr;
	int a, b;					//1111번 문제 참조.
	int result = 0;				//출력값을 의미.

	while (1)					
	{
		cin >> N;
		
		if (N>50)				//N>50 인 경우 다시 입력하게 함.
		{
			cout << "다시 입력해주세요.\n";
		}
		else
		{
			arr = new int[N];		//둘째 줄에 적는 숫자를 의미.	|arr|<=100인 정수
			break	;
		}
	}

	for (int i = 0; i<N; i++)		//둘째 줄을 입력.
	{
		cin >> arr[i];
		if (arr[i] > 100 || arr[i] < (-100))
		{
			cout << "입력하는 숫자는 -100이상 100이하만 가능합니다." << endl;
			return 0;
		}
	}

	if (N == 1)						//N=1인 경우
		cout << "A" << endl;		//왜냐하면 그 다음 값이 얼마인지 알 수 없기 때문이다.
	else if (N == 2)				//N=2인 경우
	{
		if (arr[0] == arr[1])		//만약 arr[0]=arr[1]인 경우
			cout << arr[0] << endl;	//arr[0]를 출력
		else
			cout << "A" << endl;	//왜냐하면 N=2인 경우 둘이 같지 않은 경우는 그 다음에 들어갈 값을 알수 없기 때문.
	}

	if (arr[0] == arr[1])							//arr[0]=arr[1]인 경우
		a = 0;										//a=0을 갖는다.
	else											//arr[0]!=arr[1]인 경우
		a = (arr[2] - arr[1]) / (arr[1] - arr[0]);	//a의 값

	b = arr[1] - arr[0] * a;						//b의 값

	for (int i = 2; i<N; i++)
	{
		if (arr[i - 1] != arr[i - 2] && (a != (arr[i] - arr[i - 1]) / (arr[i - 1] - arr[i - 2])))
		{
			cout << "B" << endl;
			return 0;
		}
		if (b != (arr[i - 1] - arr[i - 2] * a))
		{
			cout << "B" << endl;
			return 0;
		}
	}

	result = arr[N - 1] * a + b;

	cout << result << endl;

	return 0;
}

//상	->	수학적인 면을 생각 필요