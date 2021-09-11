#include <iostream>
using namespace std;

int main()
{
	int arr[10];				//A가 제시한 카드 순서
	int brr[10];				//B가 제시한 카드 순서
	int acnt = 0;				//A가 승리한 횟수
	int bcnt = 0;				//B가 승리한 횟수
	int sw = 0;					//0 : 비긴 경우, 1 : A가 승리, 2 : B가 승리

	for (int i = 0; i < 10; i++)
		cin >> arr[i];

	for (int i = 0; i < 10; i++)
		cin >> brr[i];

	for (int i = 0; i < 10; i++)
	{
		if (arr[i] > brr[i])
		{
			acnt += 3;
			sw = 1;
		}
		else if (arr[i] < brr[i])
		{
			bcnt += 3;
			sw = 2;
		}
		else
		{
			acnt++;
			bcnt++;
		}
	}

	cout << acnt << ' ' << bcnt << endl;

	
	if (acnt > bcnt)
		cout << 'A' << endl;
	else if (acnt < bcnt)
		cout << 'B' << endl;
	else
	{
		if (sw == 1)
			cout << 'A' << endl;
		else if (sw == 2)
			cout << 'B' << endl;
		else if (sw == 0)
			cout << 'D' << endl;
	}

	return 0;
}