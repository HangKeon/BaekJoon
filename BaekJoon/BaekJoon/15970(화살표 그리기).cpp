#include <iostream>
using namespace std;

int main()
{
	int n;								//점의 개수
	int color[5001] = { 0, };			//점의 색
	int pos[100001] = { 0, };			//점의 좌표
	int min;							//점 거리의 최솟값을 저장하는 변수
	int sum = 0;						//모든 점들에서 시작하는 화살표들의 길이 합

	cin >> n;

	for (int i = 0; i < n; i++)			//(점의 좌표, 점의 색)을 입력!
		cin >> pos[i] >> color[i];

	for (int i = 0; i < n; i++)
	{
		min = 100001;					//min을 100001로 초기화 -> 매 번마다 초기화 해줘야한다.

		for (int j = 0; j < n; j++)
		{
			if (i == j)					//자기 자신과 비교하면 안되기 때문이다. -> 그럼 무조건 점 사이 거리 = 0이 된다. 
				continue;

			if (color[i] == color[j])	//만약 색깔이 같다면
			{
				int tmp;				//점 거리 임시 저장

				if (pos[i] >= pos[j])	//점 사이 거리 구하기
					tmp = pos[i] - pos[j];
				else
					tmp = pos[j] - pos[i];

				if (min > tmp)			//만약 구한 tmp가 min보다 짧다면
					min = tmp;			//min에 tmp 대입!
			}
		}
		sum += min;
	}

	cout << sum << endl;

	return 0;
}