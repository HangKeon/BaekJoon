#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
	int n;                                  //카드 개수
	int temp;                               //임시 변수
	vector<int> v;                          //카드 저장
	queue<int> q;                           //버리는 카드를 저장


	cin >> n;

	for (int i = 1; i <= n; i++)
		v.push_back(i);

	for (int i = 0; i < n - 1; i++)
	{
		q.push(v[0]);                       //버릴 카드를 큐에 저장

		v.erase(v.begin());                 //카드를 버림
		temp = v.front();                   //현재 가장 앞에 있는 카드를 뒤로 보내기 위해 임시로 저장
		v.erase(v.begin());                 //가장 앞에 있는 카드 삭제
		v.push_back(temp);                  //가장 마지막에 카드를 넣기
	}

	q.push(v[0]);

	while(!q.empty())
	{
		cout << q.front() << ' ';
		q.pop();
	}

	return 0;
}