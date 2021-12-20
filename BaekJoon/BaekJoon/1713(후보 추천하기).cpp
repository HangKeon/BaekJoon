#include <iostream>
using namespace std;

int main()
{
	int n;						//사진틀의 갯수
	int k;						//총 추천 횟수
	int t;						//추천 받은 학생 번호
	int cnt = 0;				//현재 사용된 사진틀 갯수
	int rec[101] = { 0, };		//추천 받은 횟수
	int time[101];				//추천 받은 시점

	cin >> n >> k;

	for (int i = 1; i <= k; i++)
	{
		cin >> t;

		if (rec[t] > 0)			//이미 사진틀에 있는 경우
			rec[t]++;
		else					//새로운 번호가 들어오는 경우
		{
			if (cnt < n)		//안 사용된 사진틀이 있는 경우
			{
				rec[t]++;
				time[t] = i;
				cnt++;
			}
			else				//사진틀이 모두 사용된 경우
			{
				int Min = 1001;					//최소 횟수를 저장
				int idx;						//추천 횟수가 가장 작은 번호

				for (int j = 1; j <= 100; j++)
				{
					if (!rec[j])				//사진틀에 없는 경우 -> 패스
						continue;

					if (rec[j] < Min)			//가장 적은 추천 횟수 + 그 사람의 번호 찾기
					{
						Min = rec[j];
						idx = j;
					}
					else if (rec[j] == Min)		//추천 받은 횟수가 가장 적은 사람이 중복인 경우
					{
						if (time[j] < time[idx])	//먼저 들어온 사람의 번호를 idx에 저장!
							idx = j;
					}
				}

				rec[t]++;						//새로 추천받은 번호
				time[t] = i;					//추천받은 시간을 저장

				rec[idx] = 0;					//추천받은 횟수 초기화 -> 사진틀에서 제외되었으므로!
				time[idx] = 0;					//추천받은 시간 초기화
			}
		}
	}

	for (int i = 1; i <= 100; i++)
		if (rec[i])
			cout << i << ' ';

	return 0;
}