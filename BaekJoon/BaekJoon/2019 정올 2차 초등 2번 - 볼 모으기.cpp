#include <iostream>
using namespace std;

int cnt = 987654321;				//볼의 최소 이동횟수
int comp = 0;						//cnt와 비교하여 최소 이동횟수를 겨룬다.
int check;							//만약에 완전히 정렬이 된 경우에는 더이상 비교하지 않고 끝내기 위한 변수
char color[500001];					//볼의 색을 저장

int LeftToRight(int n);					//왼쪽에서 오른쪽으로 옮겨서 정렬하는 함수
int RightToLeft(int n);					//오른쪽에서 왼쪽을 옮겨서 정렬하는 함수

int main()
{
	int n;								//볼의 총 개수
	cin >> n;

	for(int i=0;i<n;i++)
		cin >> color[i];

	LeftToRight(n);
	RightToLeft(n);

	cout << cnt << endl;

	return 0;
}

int LeftToRight(int n)					//왼쪽에서 오른쪽으로 옮겨서 정렬하는 함수
{
	check = n - 1;						//n-1로 초기화
	for (int i = 0; i < n; i++)
	{
		if (i == check)					//만약 color[i]를 더이상 정렬할 필요가 없다면
			break;

		int j = n - 1;				//가장 오른쪽 인덱스 값
		int tcnt = 0;				//가장 오른쪽 끝 공과 색이 같으면 0이 아니다

		while (1)
		{
			if (color[i] == 'B')			//만약 현재 공의 색이 B인 경우
			{
				if (color[i] != color[j])	//만약 제일 오른쪽 끝 색과 다르다면
					break;

				j--;						//왼쪽으로 한 칸 옮겨서 비교
				tcnt++;
			}
			else if (color[i] == 'R')		//만약 현재 공의 색이 R인 경우
			{
				if (color[i] != color[j])	//만약 제일 오른쪽 끝 색과 다르다면
					break;

				j--;						//왼쪽으로 한 칸 옮겨서 비교
				tcnt++;
			}

			if (tcnt != 0 && color[i] != color[j])					//만약 color[i]를 옮길 수 있다면
			{
				char temp = color[i];		//color[i]의 색을 임시로 저장

				for (int k = i; k < j; k++)				//인덱스가 i부터 j-1까지 왼쪽으로 한 칸씩 이동
					color[k] = color[k + 1];

				color[j] = temp;			//원래 color[i]에 저장되어 있던 값을 color[j]에 저장

				comp++;
				check = j;
				i = -1;						//옮겼기 때문에 다시 처음부터 비교해야하므로 i=-1로 초기화하여 다시 시작시 i=0으로 만든다.
				break;
			}

			if (tcnt != 0 && i == j)		//만약 color 가 전부 같은 색이 나오는 경우
			{
				comp = 0;
				break;
;			}
		}
	}

	if (cnt > comp)
		cnt = comp;

	return cnt;
}

int RightToLeft(int n)						//오른쪽에서 왼쪽을 옮겨서 정렬하는 함수
{
	check = 0;						//0으로 초기화

	for (int i = n-1; i >= 0; i--)
	{
		if (i == check)					//만약 color[i]를 더이상 정렬할 필요가 없다면
			break;

		int j = 0;				//가장 오른쪽 인덱스 값
		int tcnt = 0;				//가장 오른쪽 끝 공과 색이 같으면 0이 아니다

		while (1)
		{
			if (color[i] == 'B')			//만약 현재 공의 색이 B인 경우
			{
				if (color[i] != color[j])	//만약 제일 오른쪽 끝 색과 다르다면
					break;

				j++;						//오른쪽으로 한 칸 옮겨서 비교
				tcnt++;
			}
			else if (color[i] == 'R')		//만약 현재 공의 색이 R인 경우
			{
				if (color[i] != color[j])	//만약 제일 오른쪽 끝 색과 다르다면
					break;

				j++;						//오른쪽으로 한 칸 옮겨서 비교
				tcnt++;
			}

			if (tcnt != 0 && color[i] != color[j])					//만약 color[i]를 옮길 수 있다면
			{
				char temp = color[i];		//color[i]의 색을 임시로 저장

				for (int k = i; k > j; k--)				//인덱스가 i부터 +1까지 오른쪽으로 한 칸씩 이동
					color[k] = color[k - 1];

				color[j] = temp;			//원래 color[i]에 저장되어 있던 값을 color[j]에 저장

				comp++;
				check = j;
				i = n;					//옮겼기 때문에 다시 처음부터 비교해야하므로 i=n로 초기화하여 다시 시작시 i=n-1로 만든다.
				break;
			}

			if (tcnt != 0 && i == j)		//만약 color 가 전부 같은 색이 나오는 경우
			{
				comp = 0;
				break;
			}
		}
	}

	if (cnt > comp)
		cnt = comp;

	return cnt;
}