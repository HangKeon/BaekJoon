#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;								//부품 번호(1~n-1 : 기본 부품/중간 부품, n : 완제품 번호)
int arr[101];						//진입 차수(즉, 선행되어야 하는 정점들의 개수) -> 반대로 생각!
int arr2[101];						//원래 진입 차수(즉, 선행되어야 하는 정점들의 개수)
int dp[101];						//필요한 기본 부품의 개수를 저장
vector<pair<int,int> > v[101];		//v[x] = {y, k} : 그래프(y -> x일 때, x를 만들기 위해 y가 k개 필요)
									//but 화살표를 반대로 생각해서 풀자!(즉, x -> y일 때, y를 만들기 위해 x가 k개 필요)

void topology()
{
	queue<int> q;					//진입차수가 0인 값을 저장

	for(int i=1;i<=n;i++)
		if (!arr[i])
			q.push(i);

	dp[n] = 1;

	for (int i = 1; i <= n; i++)
	{
		int x = q.front();
		q.pop();

		for (int j = 0; j < v[x].size(); j++)
		{
			int a = v[x][j].first;	//x와 연결된 부품 번호
			int b = v[x][j].second;	//b에 a를 만드는 데 필요한 x의 개수 저장

			dp[a] += b * dp[x];

			if (--arr[a] == 0)
				q.push(a);
		}
	}

	for (int i = 1; i <= n; i++)	//arr2가 0인 경우만 출력(기본 부품인 경우)
		if (!arr2[i])
			cout << i << ' ' << dp[i] << endl;
}

int main()
{
	int m;							//부품들 간의 관계의 개수
	int x, y, k;					//x : 중간 부품/완제품, y : 기본 부품/중간 부품, k : x를 만들기 위한 y의 개수

	cin >> n >> m;

	for (int i = 1; i <= m; i++)
	{
		cin >> x >> y >> k;

		v[x].push_back({ y,k });	//(x -> y), [큰값 -> 작은 값]으로 해서 반대로 생각
		arr[y]++;					//y의 진입차수 1 증가
		arr2[x]++;					//원래 진입 차수를 1 증가
	}

	topology();

	return 0;
}