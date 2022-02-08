#include <iostream>
#include <algorithm>
using namespace std;

//틀린 코드

int main()
{
	int n;							//학생 수
	int idx = 0;					//결정된 후보 번호(결정 못하는 경우 = 0)
	int max_score = -1;				//최고 점수
	int sw = 0;						//0 : 회장을 결정할 수 없는 경우, 1 : 회장이 결정된 경우
	int sw2 = 0;					//0 : 회장을 결정할 수 없는 경우, 1 : 회장이 결정된 경우
	int arr[1001][4];				//arr[학생 수][후보 번호] = 점수
	int arr2[4][4] = { 0 };			//arr2[후보 번호][0 : 총 점수, 1~3] = 받은 점수 횟수

	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 1; j <= 3; j++)
		{
			cin >> arr[i][j];

			arr2[j][arr[i][j]]++;			//받은 점수 별 횟수 1증가

			arr2[j][0] += arr[i][j];		//총 점수
		}

	for (int i = 1; i < 3; i++)
	{
		for (int j = i + 1; j <= 3; j++)
		{
			if (max_score <= arr2[i][0])					//max_score보다 큰 경우만 살펴보기!
			{
				if (arr2[i][0] > arr2[j][0])				//i의 점수 > j의 점수
				{
					idx = i;
					max_score = arr2[i][0];
				}
				else if (arr2[i][0] < arr2[j][0])			//i의 점수 < j의 점수
				{
					idx = j;
					max_score = arr2[j][0];
				}
				else										//i의 점수 = j의 점수
				{
					for (int k = 3; k > 0; k--)				//1~3점 사이
					{
						if (arr2[i][k] > arr2[j][k])		//i의 k점 > j의 k점
						{
							idx = i;
							max_score = arr2[i][0];
							break;
						}
						else if (arr2[i][k] < arr2[j][k])	//i의 k점< j의 k점
						{
							idx = j;
							max_score = arr2[j][0];
							break;
						}
					}
				}
			}
		}
	}

	//이 부분 미완성
	if (sw || sw2)
	{
		cout << idx << ' ' << max_score << endl;
		return 0;
	}
	else					//회장 결정을 못한 경우
	{
		idx = 0;

		for (int i = 1; i <= 3; i++)	//최고 점수 비교 후 저장
			max_score = max(max_score, arr2[i][0]);
	}

	cout << idx << ' ' << max_score << endl;


	return 0;
}