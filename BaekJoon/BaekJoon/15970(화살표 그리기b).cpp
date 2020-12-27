#include <iostream>
using namespace std;

int main()
{
	int n;								//점의 개수
	int pos[5001];						//점의 위치
	int sum = 0;						//화살표의 길이의 합
	int min;							//각 점마다의 화살표 길이의 최솟값
	int tmp;							//화살표의 임시 길이

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> pos[i];
	
	for (int i = 0; i < n; i++)
	{
		min = 100001;					//왜냐하면 점의 좌표의 최대 위치는 100000이기 때문이다.

		for (int j = 0; j < n; j++)
		{
			if (i == j)					//만약 같은 점이라면
				continue;

			if (pos[i] >= pos[j])
				tmp = pos[i] - pos[j];
			else
				tmp = pos[j] - pos[i];

			if (min > tmp)				//최솟값 > 화살표의 길이
				min = tmp;
		}

		sum += min;						//점pos[i]에서의 최소 화살표 길이 min을 합 sum에 더하기
	}

	cout << sum << endl;



	return 0;
}