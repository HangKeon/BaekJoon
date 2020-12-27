#include <iostream>
using namespace std;

int pal(char [], int, int);				//pal(확인할 문자열, 마지막 인덱스, 중간 인덱스)

int main()
{
	int t;								//주어지는 문자열의 개수
	char arr[100001];					//회문, 유사회문, 아무 것도 아닌지 판단할 문자열
	int result[31];						//0,1,2를 저장할 배열
	int l, m;							//l : 전체 개수 -1, m : 중간값( (ㅣ+1)/2 )

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> arr;

		l = strlen(arr) - 1;			//배열의 마지막을 지정하기 위한 변수
		m = (l+1) / 2;					//배열의 중간 인덱스를 구하기 위한 변수

		result[i] = pal(arr, l, m);		//result에 0,1,2를 저장!

	}

	for (int i = 0; i < t; i++)
		cout << result[i] << endl;

	return 0;
}




int pal(char arr[], int l, int m)			//pal(확인할 문자열, 마지막 인덱스, 중간 인덱스)
{
	int move = 0;							//0이면 회문, 1이면 유사회문, 2이면 아무 것도 아닌 걸로 인식한다.
	int i = 0;								//회문, 유사회문의 인덱스로 회문을 검사하다가 아니면 유사회문으로 넘어갈 때 거기서부터 시작!

	for (i = 0; i <= m; i++)				//i<=m이면 개수가 홀수이든 짝수이든 모두 성립 -> 겨우1번 더 보는 것이므로 큰 영향 없음.
	{
		if (arr[i] != arr[l - i])			//회문이 아닌 경우
		{
			move = 1;						//이제 유사회문 인지 확인하기 위해 move값을 1로 바꿈
			break;
		}
	}

	if (move == 1)							//move값이 1인 경우 -> 즉, 유사회문일 가능성이 있는 경우
	{
		int k = l - i;						//유사회문은 오른쪽, 왼쪽 중 하나를 없애고 비교해야 하므로 ㅣ-i를 따로 정한다.
		int change = 0;						//change=0이면 arr[i]를 제외하고 비교, change=1이면 arr[k]를 제외하고 비교!

		for (int c = i + 1; c <= k; c++)	//arr[i](=왼쪽)를 제외하고 비교하는 경우 -> 단, 이 경우는 처음부터 끝까지 다 비교한다.
		{
			if (arr[c] != arr[l - c + 1])	//왼쪽을 제외하고 비교했는데 유사회문이 아닌 경우
			{
				change = 1;
				break;
			}
		}

		if (change == 1)						//왼쪽을 제외하고 비교했는데 유사회문이 아닌 경우
		{
			for (int c = i; c < k; c++)			//arr[k]인 경우(오른쪽)를 제외하고 비교한 경우 -> 단, 이 경우는 처음부터 끝까지 다 비교한다.
			{
				if (arr[c] != arr[l - c - 1])	//오른쪽을 제외하고 비교했는데 유사회문이 아닌 경우
				{
					move = 2;
					break;
				}
			}
		}
	}

	return move;
}