#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//<성립 조건>
//1) 양수인 경우 큰 수끼리 곱해야 큰 값이 더해질 것이다.
//2) 음수 또한 절대값이 큰 음수끼리 곱하면 더해진 값이 커질 것이다.
//3) 1은 곱하는 것 보단 더하는 게 결과값이 커지게 된다.
//4) 음수의 개수가 홀수일 때 마지막 남은 한 개의 음수는 0을 곱해주는 게 결과값이 가장 커지게 된다.

int main()
{
	int n;							//수열의 크기
	int temp;						//입력값
	int zero = 0;					//0의 개수를 저장
	int one = 0;					//1의 개수를 저장
	int sum;						//최대 합
	vector<int> pos;				//양수를 저장(1보다 큰 양수)
	vector<int> neg;				//음수를 저장

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> temp;

		if (temp > 1)
			pos.push_back(temp);
		else if (temp < 0)
			neg.push_back(-temp);	//나중에 오름차순 정렬하기 위해 음수를 붙여줌
		else if (temp == 0)
			zero++;
		else
			one++;
	}

	if (pos.size() % 2 == 1)		//양수가 홀수개인 경우 -> 1을 추가해 짝수 개로 맞춘다
		pos.push_back(1);			//왜냐하면 양수끼리 곱해줄 것인데, 괄호는 2개당 1개를 만들어야 하기 때문

	if (neg.size() % 2 == 1)		//음수가 홀수개인 경우 -> 음수를 곱했을 때 1개는 음수가 됨
	{
		if (zero == 0)				//0이 없다면 -> 가장 작은 값을 음수로 바꿔줌. 그래서 -1을 추가!
			neg.push_back(-1);
		else						//0이 있다면 -> 음수 1개를 0과 곱하도록 함! => 4번 조건
			neg.push_back(0);
	}

	sort(pos.begin(), pos.end());
	sort(neg.begin(), neg.end());

	sum = one;

	for (int i = 0; i < pos.size(); i += 2)	
		sum += pos[i] * pos[i + 1];

	for (int i = 0; i < neg.size(); i+=2)
		sum += neg[i] * neg[i + 1];

	cout << sum << endl;

	return 0;
}