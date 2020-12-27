#include <iostream>
using namespace std;

int GCD(int, int);
int LCM(int, int);

int main()
{
	int num = 0, a[50], b[50], c[50], gcd = 0, lcm = 0;		//num=약수의 개수, a,b,c=입력할 약수 및 복사
															//gcd=최대공약수, lcm=최소공배수
	cin >> num;			//입력할 약수의 개수

	for (int i = 0; i < num; i++)
	{
		cin >> a[i];	//약수를 입력
		b[i] = a[i];	//입력한 약수를 b,c에 복사
		c[i] = a[i];	//이렇게 하는 이유는 아래 GCD(a[i],a[i+1])을 할 때 a[i+1]에 
	}					//GCD의 값을 집어넣으므로 원래 입력한 값을 유지할 수 없기 때문


	for (int i = 0; i < num - 1; i++)
	{
		a[i + 1] = GCD(a[i], a[i + 1]);		//a[i]와 a[i+1] 사이의 GCD를 a[i+1]에 넣어 for문을 적용할 수 있게 함.
		gcd = a[i + 1];

		b[i + 1] = LCM(b[i], b[i + 1]);		//b[i]와 b[i+1] 사이의 LCM을 b[i+1]에 넣어 for문을 적용할 수 있게 함.
		lcm = b[i + 1];
	}

	for (int i = 0; i < num; i++)
	{
		if (lcm == c[i])					//만약 lcm이 입력한 약수와 같다면
		{
			lcm *= 2;						//무조건 2를 곱해라 -> 왜냐하면 1037번 문제에서 입력한 값은 1과 자기 자신을
		}									//제외한 약수라고 적혀 있기 때문.
		else if (lcm == 1)
			break;
	}

	cout << "최대공약수 = " << gcd << endl;
	cout << "최소공배수 = " << lcm << endl;


	return 0;
}

int GCD(int a,int b)				//최대공약수
{				
	int c;

	while (b != 0)
	{
		c = a%b;
		a = b;
		b = c;
	}
	
	return a;
}

int LCM(int a, int b)				//최소공배수
{
	return a*b / GCD(a, b);
}

//중