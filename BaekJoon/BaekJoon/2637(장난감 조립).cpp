#include <iostream>
#include <algorithm>
using namespace std;
//2000년 중등부 1번

int main()
{
	int n;						//제품의 번호, 1 ~ n번까지 존재
	int m;						//어떤 부품을 완성하는데 필요한 부품들 간의 관계를 나타내는 조건 개수
	int x, y, k;				//중간 부품이나 완제품 X를 만드는데 중간 부품 혹은 기본 부품 Y가 K개 필요하다
	int flag = 1;
	int arr[101] = { 0, };		//최종 갯수를 저장할 배열
	int arr2[101] = { 0, };		//기본 부품을 찾기 위한 배열 -> 0 : 기본부품
	int v[101][101] = { 0, };	//v[x][y]=k

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> x >> y >> k;
		
		arr2[x] = 1;					//x에 한 번이라도 언급된 것들은 기본 부품이 아니므로 arr2에 1을 대입

		v[x][y] = k;
	}
	
	for (int i = 1; i < n; i++)
		arr[i] = v[n][i];				//최종 부품 n과 연결된 중간 or 기본 부품들을 arr에 저장!

	while (flag)						//여러 번 반복하기 위해서 flag를 사용!
	{
		flag = 0;

		for (int i = 1; i < n; i++)
		{
			if (arr[i] != 0 && arr2[i] == 1)
			{
				flag = 1;

				for (int j = 1; j < n; j++)
					arr[j] += v[i][j] * arr[i];

				arr[i] = 0;				//다른 부품들과 연결되어 있는 경우 영향을 주지 않기 위해 0으로 초기화
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (!arr2[i])
		{
			cout << i << ' ' << arr[i] << endl;
		}
	}

	return 0;
}