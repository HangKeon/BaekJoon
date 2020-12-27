#include <iostream>
using namespace std;

int main()
{
	int n, k;						//n : 공의 개수, k : 팀의 수

	cin >> n >> k;

	n -= k * (k + 1) / 2;			

	if (n < 0)						//모두 다 다르고 최대한 차이를 적게 해야 하기 때문
		cout << "-1";
	else
	{
		if(n%k!=0)					//안 나눠떨어지는 경우는 분명히 공의 남기 때문이다.
			cout << k << endl;
		else						//나눠떨어지는 경우는 그만큼 균등하게 공을 나누면 되기 때문에 항상 일정!
			cout << k - 1 << endl;
	}
	   	 
	return 0;
}