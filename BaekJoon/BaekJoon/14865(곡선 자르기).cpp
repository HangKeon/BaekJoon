#include <iostream>
using namespace std;


int panx[1000006];

int tc = 0;

int pany[1000006];

int realbong = 0;

bool flag = false;

void cCheck() 
{

	int cnt = 0;

	int inc = 0;//봉우리 포함 수

	int notInc = 0;//봉우리 포함 안하는 수 

	int open = 0;

	for (int i = 0; i < realbong; i++) 
	{//봉우리 괄호화

		if (pany[i] != 0) 
		{

			for (int j = i + 1; j < realbong; j++) 
			{//i+1인 이유는 다음순서부터 똑같은 높이의 녀석을 찾아야하니..

				if (pany[i] == pany[j]) 
				{

					panx[i] = -1; // '('

					panx[j] = 1; // ')'

					pany[i] = 0;//사용했으므로 바꿔준다.

					pany[j] = 0;

					break;

				}

			}

		}

	}

	for (int i = 0; i < realbong; i++) 
	{

		if (panx[i] == -1) 
		{//여는부분

			if (!flag) 
			{//새로이 열었을때

				flag = true;

			}

		}

		else if (panx[i] == 1) 
		{//닫는부분

			if (flag) 
			{//포함 안하는봉우리

				notInc++;

			}

			else 
			{//포함하는 봉우리

				inc++;

			}

			flag = false;//닫혔을때 flag를 false로 바꿔준다.

		}

	}

	cout << inc << " " << notInc << endl;

}

void sort() 
{

	int temp;

	for (int i = 0; i < realbong; i++) 
	{

		for (int j = i + 1; j < realbong; j++) 
		{

			if (panx[i] > panx[j]) 
			{

				temp = panx[i];

				panx[i] = panx[j];

				panx[j] = temp;

				temp = pany[i];

				pany[i] = pany[j];

				pany[j] = temp;

			}

		}

	}

}

int main() 
{

	cin >> tc;

	int tempx;

	int tempy;

	for (int i = 0; i < tc; i++) 
	{

		cin >> tempx >> tempy;

		if (tempy > 0) 
		{

			panx[realbong] = tempx;

			pany[realbong] = tempy;

			realbong++;

		}

	}

	sort();

	cCheck();

	return 0;

}