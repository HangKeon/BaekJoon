#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n;						//점의 갯수
	int x, y;					//x : 점의 좌표, y : 점의 색깔
	long long sum = 0;			//전체 길이의 합
	vector<int> v[100001];		//v[색깔] = 좌표 : 색깔의 인덱스에 그 좌표들을 쌓는다.

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;

		v[y].push_back(x);
	}

	for (int i = 1; i <= n; i++)
	{
		int size = v[i].size();

		if (size < 2)			//이건 정렬할 필요 없는 것(왜냐하면 없거나 1개)
			continue;

		sort(v[i].begin(), v[i].end());

		for (int j = 0; j < size; j++)
		{
			if (j == 0)						//제일 앞의 점인 경우
				sum += v[i][j + 1] - v[i][j];
			else if (j == size - 1)			//제일 뒤의 점인 경우
				sum += v[i][j] - v[i][j - 1];
			else							//나머지
				sum += min(v[i][j + 1] - v[i][j], v[i][j] - v[i][j - 1]);
		}
	}

	cout << sum << endl;

	return 0;
}