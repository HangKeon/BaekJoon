#include <iostream>
using namespace std;

int arr[20][4] = { 0, };		//문제에서 n<=20이므로 첫 배열은 20까지, 두번째 배열은 도보, 도보money, 자전거, 자전거money로 4개!
int arr2[20] = { 0, };			//이건 arr에서 필요하므로 arr의 첫번째 배열과 같은 값으로 지정!
int n, k;						//n = 구간의 개수, k = 걸리는 최대시간
int time, money, best = 0;		//time = 걸리는 시간의 합, money = 모든 돈의 합, best = 조건을 만족하는 money 중 최대값!

void GetBest(int num)
{
	if (n == num)									//만약 n == num 이라면
	{
		time = 0;									//time = 0 으로 초기화
		for (int i = 0; i < n; i++)
			time += arr[i][arr2[i]];				//main함 수에서 입력한 arr값을 time 에 추가!
													//여기서 arr2를 사용한 이유는 time 이므로 초기값 = 0 인 arr2를 사용한 것!
		if (time <= k)								//time <= k 라면 -> 문제의 조건에 성립!
		{
			money = 0;								//money = 0 으로 초기화
			for (int i = 0; i < n; i++)
				money += arr[i][arr2[i] + 1];			//main 함수에서 입력한 arr값을 money 에 추가!
														//arr2[i]+1 사용 이유는 arr의 두번째 배열이 money이기 때문!
			if (best < money)
				best = money;
		}

		return;
	}

	arr2[num] = 0;									//arr2를 0으로 초기화 함으로써 '도보' 이용할 때의 값을 구할 수 있다!
	GetBest(num + 1);								//num을 입력한 n과 같은 값이 될 때까지 증가!

	arr2[num] = 2;
	GetBest(num + 1);

}


int main()
{
	cin >> n >> k;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < 4; j++)
			cin >> arr[i][j];

	GetBest(0);

	cout << best << endl;


	return 0;
}

//상