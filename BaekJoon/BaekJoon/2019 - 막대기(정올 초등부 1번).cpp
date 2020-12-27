#include <iostream>
using namespace std;

int main()
{
	int n;								//막대기 개수
	int stick[100001];					//막대기 높이 저장
	int cnt = 0;						//오른쪽에서 볼 때 보이는 막대의 개수
	int MAX = 0;						//최대 막대 길이를 저장

	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> stick[i];

	for (int i = n; i >= 1; i--)		//오른쪽부터 비교하기 시작
		if (MAX < stick[i])				//MAX보다 큰 경우
		{
			MAX = stick[i];				//MAX에 저장함으로써 왼쪽에서 MAX보다 작은 막대들은 세지 않는다.
			cnt++;
		}

	cout << cnt << endl; 

	return 0;
}