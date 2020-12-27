#include <iostream>
using namespace std;

int main()
{
	int n;							//스위치의 개수(100 이하의 자연수)
	int arr[101];					//스위치의 상태를 저장할 배열(0 : 꺼짐, 1 : 켜짐)
	int std;						//학생 수(100 이하의 자연수)
	int s, num;						//s : 성별(1 : 남, 2 : 여), num : 학생이 받은 스위치 번호(스위치 개수 이하의 수 중 하나)
	int cnt;						//s가 여자인 경우, 좌우 대칭을 해야 하므로 옮길 인덱스

	cin >> n;

	for (int i = 1; i <= n; i++)		//arr의 인덱스를 스위치 번호로 생각하기 위해 1부터 저장!
		cin >> arr[i];

	cin >> std;

	for (int i = 0; i < std; i++)
	{
		cin >> s >> num;

		cnt = 0;					//초기화

		if (s == 1)					//남자인 경우
		{
			for (int j = num; j <= n; j+=num)	//스위치를 비교할 것임
			{
				if (arr[j] == 0)
					arr[j] = 1;
				else if (arr[j] == 1)
					arr[j] = 0;				
			}
		}
		else if (s == 2)			//여자인 경우
		{
			while (num - cnt > 0 && num + cnt <= n)			//좌우 대칭한 스위치 번호가 1보다 작아지거나 n보다 커지면 stop!
			{
				if (arr[num - cnt] == arr[num + cnt])	//만약 arr[num]을 기준으로 좌우 대칭의 스위치 상태가 같다면 -> 바꾼다
				{
					if (arr[num + cnt] == 0)
					{
						arr[num + cnt] = 1;
						arr[num - cnt] = 1;
					}
					else if (arr[num + cnt] == 1)
					{
						arr[num + cnt] = 0;
						arr[num - cnt] = 0;
					}
				}
				else									//만약 arr[num]을 기준으로 좌우가 다르다면 stop!
				{
					break;
				}
				cnt++;
			}
		}
	}

	for (int i = 1; i <= n; i++)		//출력
	{
		cout << arr[i] << ' ';

		if (i % 20 == 0)				//한 줄에 최대 20개씩 출력이 되야 한다!
		{
			cout << endl;
		}
	}
		
	cout << endl;

	return 0;
}