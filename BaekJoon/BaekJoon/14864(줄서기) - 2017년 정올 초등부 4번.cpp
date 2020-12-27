#include <iostream>
#include<vector>
using namespace std;

int main()
{
	int n, m;						//n : 학생 수, m : 순서쌍 수
	vector<int> v;					//학생1~n까지 저장
	vector<int> visited;			//이미 방문한 v[i]에 1을 저장!

	cin >> n >> m;

	v.resize(n + 1);				//n+1만큼 크기를 만듬.
	visited.resize(n + 1);

	for (int i = 1; i <= n; i++)		//인덱스 값에 맞추어 학생들의 번호를 저장 -> 우선은 이것을 카드 번호로 생각하자!
		v[i] = i;

	while (m--)
	{
		int a, b;					//학생 X,Y를 순서대로 입력
		cin >> a >> b;

		v[a]++;						//X위치에 언급되면 1씩 증가
		v[b]--;						//Y위치에 언급되면 1씩 감소
	}

	for (int i = 1; i <= n; i++)		//-1을 출력할 조건
	{
		if (v[i]<1 || v[i]>n)			//만약 v에 저장된 값이 1보다 작거나 n보다 커지면
		{
			cout << "-1" << endl;
			return 0;
		}

		if (visited[v[i]])				//중복된 값이 있다면
		{
			cout << "-1" << endl;
			return 0;
		}

		visited[v[i]]++;				//만약 한 번도 방문한 적이 없다면 1 증가!
	}

	for (int i = 1; i <= n; i++)
		cout << v[i] << ' ';

	cout << endl;

	return 0;
}