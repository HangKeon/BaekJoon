#include <stdio.h>
#include <string.h>

void main()

{

	/*------------------------------------------*/

	/*input num: ���� �����Դϴ�.*/

	/*input string: ���� ó�� ���ĵ� �����Դϴ�.*/

	/*A: ���ĵ� ���� ��Ÿ���� �迭�Դϴ�.*/

	/*------------------------------------------*/




	int inputNum;

	char inputString[500000];

	char A[500000];




	scanf_s("%d", &inputNum);

	for (int i = 0; i < inputNum; i++)
		scanf_s("%c", &inputString[i]);




	for (int i = 0; i < inputNum; i++)
		A[i] = inputString[i];

	/*���� ���� �󸶳� �Ű� ���ĸ� �ߴ��� ��Ÿ���� ���Դϴ�.*/

	int redMoveNum = 0;

	/*�ؼ����� ������ ������ ���� ���� �����մϴ�.*/

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

	/*�� ���� ���� �ű� ���� ����մϴ�.*/

	if (redMoveNum > blueMoveNum)

		printf("%d\n", blueMoveNum);

	else

		printf("%d\n", redMoveNum);

}