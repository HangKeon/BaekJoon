#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
int visited[100001];				//방문했는지 확인

int main()
{
	int n, m;						//n : 학생수, m : 순서쌍 수
	int a, b;

	cin >> n >> m;

	for (int i = 0; i <= n; i++)	//학생 번호를 갖고 있는 카드로 두고 시작하자
		v.push_back(i);

	while (m--)
	{
		cin >> a >> b;
		v[a]++;						//앞에 나온 학생은 카드 번호 증가
		v[b]--;						//뒤에 나온 학생은 카드 번호 감소
	}

	for (int i = 1; i <= n; i++)
	{
		if (v[i] <= 0 || v[i] > n)	//1~n의 범위가 아닌 경우
		{
			cout << "-1" << endl;
			return 0;
		}

		if (visited[v[i]])			//이미 누군가가 v[i]를 가진 경우
		{
			cout << "-1" << endl;
			return 0;
		}

		visited[v[i]] = 1;			//방문처리
	}

	for (int i = 1; i <= n; i++)
		cout << v[i] << ' ';

	cout << endl;


	return 0;
}