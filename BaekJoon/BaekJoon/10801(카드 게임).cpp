#include <iostream>
using namespace std;

int main()
{
	int arr[10];				//A가 제시한 카드 순서
	int brr[10];				//B가 제시한 카드 순서
	int acnt = 0;				//A가 승리한 횟수
	int bcnt = 0;				//B가 승리한 횟수

	for (int i = 0; i < 10; i++)
		cin >> arr[i];
	
	for (int i = 0; i < 10; i++)
		cin >> brr[i];

	for (int i = 0; i < 10; i++)
	{
		if (arr[i] > brr[i])
			acnt++;
		else if (arr[i] < brr[i])
			bcnt++;
	}

	if (acnt > bcnt)
		cout << 'A' << endl;
	else if (acnt < bcnt)
		cout << 'B' << endl;
	else
		cout << 'D' << endl;

	return 0;
}