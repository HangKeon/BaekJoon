#include <iostream>
#include <algorithm>
using namespace std;

int GCD(int a, int b);

//이 두 배열은 밖에 선언하지 않으면 런타임 에러가 난다!!
int card[101];					//종이에 수를 저장하는 배열
int arr[101];					//gcd의 약수들을 저장할 배열

int main()
{
	int n;							//종이에 적은 수의 개수(2 ~ 100)
	int gcd;						//card[1]-card[0] ~ card[i]-card[i-1]의 최대공약수를 저장
	int num = 0;					//gcd의 약수를 arr에 저장할 때 사용할 인덱스 겸 약수의 개수
	
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> card[i];

	sort(card, card + n);			//card 배열을 오름차순으로 정렬한다 -> 왜냐하면 card[i]-card[i-1]의 값들을 구해야 하기 때문이다.

	gcd = card[1] - card[0];		//gcd는 최대공약수를 구해야 하므로 처음 비교값이 필요하다

	for (int i = 2; i < n; i++)		//최대공약수를 구한다
		gcd = GCD(gcd, card[i] - card[i - 1]);

	for (int i = 1; i*i <= gcd; i++)		//예를 들어 24의 약수는 1,2,3,4,6,8,12,24이다. 
	{										//이때, 4까지만 구하면 나머지는 구할 필요가 없으므로 i*i <= gcd라는 조건이 성립한다.
		if (gcd%i == 0)						//만약 gcd가 i로 나누어 떨어진다면
		{
			arr[num++] = i;					//i는 gcd의 약수이므로 arr에 저장

			if (i != gcd / i)				//i가 gcd의 약수라면 gcd/i도 gcd의 약수이므로 이것도 저장해야 한다
				arr[num++] = gcd / i;
		}
	}

	sort(arr, arr + num);					//arr을 오름차순으로 정렬 -> 이때, arr은 gcd의 약수 1을 갖고 있다.

	for (int i = 0; i < num; i++)			//출력
	{
		if (arr[i] != 1)
			cout << arr[i] << ' ';
	}
	cout << endl;

	return 0;
}

int GCD(int a, int b)				//최대공약수 ->GCD(원래 수, 나누는 수)
{
	int c;							//나머지

	while (b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}

	return a;
}