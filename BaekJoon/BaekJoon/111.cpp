#include <stdio.h>
#include <string.h>

void main()

{

	/*------------------------------------------*/

	/*input num: 공의 개수입니다.*/

	/*input string: 공의 처음 정렬된 상태입니다.*/

	/*A: 정렬된 공을 나타내는 배열입니다.*/

	/*------------------------------------------*/




	int inputNum;

	char inputString[500000];

	char A[500000];




	scanf_s("%d", &inputNum);

	for (int i = 0; i < inputNum; i++)
		scanf_s("%c", &inputString[i]);




	for (int i = 0; i < inputNum; i++)
		A[i] = inputString[i];

	/*빨간 공을 얼마나 옮겨 정렬를 했는지 나타내는 수입니다.*/

	int redMoveNum = 0;

	/*해설에서 설명한 방법대로 빨간 공을 정렬합니다.*/

	for (int i = inputNum - 1; i >= 0; i--)

	{

		if (A[i] == 'B')

		{

			char temp;

			for (int j = i; j >= 0; j--)

			{

				if (A[j] == 'R')

				{

					temp = A[i];

					A[i] = A[j];

					A[j] = temp;

					redMoveNum++;

					break;

				}

			}

		}

	}




	for (int i = 0; i < inputNum; i++)

		A[i] = inputString[i];




	int blueMoveNum = 0;




	for (int i = inputNum - 1; i >= 0; i--)

	{

		if (A[i] == 'R')

		{

			char temp;

			for (int j = i; j >= 0; j--)

			{

				if (A[j] == 'B')

				{

					temp = A[i];

					A[i] = A[j];

					A[j] = temp;

					blueMoveNum++;

					break;

				}

			}

		}

	}

	/*더 적게 공을 옮긴 쪽을 출력합니다.*/

	if (redMoveNum > blueMoveNum)

		printf("%d\n", blueMoveNum);

	else

		printf("%d\n", redMoveNum);

}