#include <iostream>
using namespace std;

int main()
{
	int n;								//각 반의 수
	int std;							//각 반의 학생 수
	int score[1000];					//학생의 점수
	int sum = 0;						//각 반의 점수의 합
	int cnt = 0;						//평균을 넘는 학생의 수
	float avg;							//각 반의 평균 점수
	float percent[10];					//각 반의 점수 평균을 넘는 학생의 비율

	cin >> n;

	for (int i = 0; i < n; i++)			//입력
	{
		cin >> std;
		sum = 0;

		for (int j = 0; j < std; j++)
		{
			cin >> score[j];
			sum += score[j];
		}

		avg = (float)(sum / std);		//평균 구함

		for (int j = 0; j < std; j++)
		{
			if (avg < score[j])			//평균보다 크다면
				cnt++;
		}

		percent[i] = ((float)cnt / std) * 100;
		cnt = 0;
	}

	for (int i = 0; i < n; i++)
	{
		cout << fixed;
		cout.precision(3);
		cout << percent[i] << '%' << endl;
	}




	return 0;
}