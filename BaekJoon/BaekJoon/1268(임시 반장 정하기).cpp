#include <iostream>
#include <algorithm>
using namespace std;

int n;						//반의 학생 수
int idx = 1;				//임시 반장인 학생 번호
int temp = -1;				//같은 반이었던 최대 학생 수
int arr[1001][6];			//arr[학생 번호][반 번호] = 같은 반이었던 학생 번호
int arr2[1001];				//자신과 같은 반이었던 학생 수를 저장(자기 자신 제외)
int arr3[1001][1001];		//arr[i][j] : i와 같은 반이 한 번이라도 있는 학생을 1로 저장!

int main()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= 5; j++)
			cin >> arr[i][j];

	for (int k = 1; k < 6; k++)
	{
		for (int i = 1; i < n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				//if (i == j)						//자기 자신은 넘어감
				//	continue;

				if (arr[i][k] == arr[j][k] && arr3[i][j] != 1)		//i와 j가 같은 반이었다면 -> arr2[i],arr2[j]를 증가!
				{
					arr2[i]++;
					arr2[j]++;

					arr3[i][j] = 1;
					arr3[j][i] = 1;
				}
			}
		}
	}

	for(int i=1;i<=n;i++)
		if (arr2[i] > temp)
		{
			temp = arr2[i];
			idx = i;
		}

	cout << idx << endl;

	return 0;
}