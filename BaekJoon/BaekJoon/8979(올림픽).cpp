#include <iostream>
using namespace std;

int main()
{
	int n, k;               //n : 국가 수, k : 등수를 알고 싶은 국가
	int idx;               //국가 번호
	int cnt = 0;            //k번 국가보다 더 잘한 국가의 수
	int gold[1001];            //금메달
	int silver[1001];         //은메달
	int bronze[1001];         //동메달

	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		cin >> idx;
		cin >> gold[idx] >> silver[idx] >> bronze[idx];
	}

	for (int i = 1; i <= n; i++)
		if (gold[i] > gold[k])
			cnt++;
		else if (gold[i] == gold[k])
			if (silver[i] > silver[k])
				cnt++;
			else if (silver[i] == silver[k])
				if (bronze[i] > bronze[k])
					cnt++;

	cout << cnt + 1 << endl;


	return 0;
}