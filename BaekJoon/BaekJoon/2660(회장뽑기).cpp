#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr[51][51];				//arr[i][j] : i -> j까지 도달하는 횟수

int main()
{
	int n;						//회원 수
	int a = 0, b = 0;			//회원번호
	int cnt = 0;				//회장 후보 수
	int ans = 100;				//회장 후보 점수
	int temp;					//학생마다 가장 큰 점수를 저장
	vector<int> v;				//회장 후보를 저장

	cin >> n;

	for (int i = 1; i <= n; i++)		//큰 값으로 초기화
		for (int j = 1; j <= n; j++)
			if (i != j)
				arr[i][j] = 100;

	while (1)
	{
		cin >> a >> b;

		if (a + b == -2)		//탈출조건
			break;

		arr[a][b] = 1;
		arr[b][a] = 1;
	}

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);	//가능한 횟수만큼 더해준다.


	for (int i = 1; i <= n; i++)
	{
		temp = 0;							//처음에 무조건 바뀔 수 있도록 0으로 초기화

		for (int j = 1; j <= n; j++)
		{
			temp = max(temp, arr[i][j]);	//학생의 가장 큰 점수를 찾기
		}

		if (temp <= ans)					//더 작은 점수 존재하면
		{
			if (ans != temp)				//점수가 다른 경우 회장 후보를 다시 저장
				v.clear();

			ans = temp;						//그걸 회장 후보 점수로 교체

			v.push_back(i);					//회장 후보 저장
		}
	}

	sort(v.begin(), v.end());

	cout << ans << ' ' << v.size() << endl;

	for (int i = 0; i < v.size(); i++)
		cout << v[i] << ' ';

	return 0;
}