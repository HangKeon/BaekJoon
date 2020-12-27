#include <iostream>
using namespace std;

int main()
{
	int N;													//반의 수
	float inspect = 0;										//평균을 초과한 학생 수
	float sum = 0;											//학생 점수 합

	cin >> N;												//반의 수 입력

	int *team = new int[N];								//각 반의 인원수를 적는 배열
	int *score;											//각 반 학생들의 점수
	float *avg = new float[N];								//학생 정수 평균
	float student_per[50];									//avg를 넘은 학생들의 비율

	for (int i = 0; i<N; i++)
	{
		cin >> team[i];									//반의 학생 수 입력
		score = new int[team[i]];
		//student_per = new float[i];
		//avg = new float[i];

		for (int j = 0; j<team[i]; j++)
		{
			cin >> score[j];								//각 학생들의 점수 입력
			sum += score[j];								//점수들의 합
		}

		avg[i] = sum / team[i];								//점수 평균

		for (int k = 0; k < team[i]; k++)					//각 학생 점수와 평균 점수 비교
		{
			if (score[k] > avg[i])							//학생 점수가 평균보다 높을 경우
				inspect++;
		}

		cout << fixed;										//이건 소수점을 고정시켜 표현
		cout.precision(3);									//소수점 넷째자리에서 반올림해서 소수점 셋째자리까지만 표기
		student_per[i] = float(inspect / team[i]) * 100;		//평균을 넘은 학생 비율

		inspect = 0;										//inspect를 초기화
		sum = 0;											//sum을 초기화
	}

	for (int i = 0; i<N; i++)
	{
		//cout << "sum : " << sum << endl;
		//cout << "평균 : " << avg[i] << endl;
		//cout << "inspect : " << inspect << endl;
		//cout << "team[i] : " << team[i] << endl;
		cout << student_per[i] << "%" << endl;
	}

	return 0;
}

//중상