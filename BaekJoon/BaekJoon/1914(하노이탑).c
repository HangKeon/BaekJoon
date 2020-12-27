 #include <stdio.h>

void HanoiTowerMove(int n, int a, int b, int c)
{
	if (n == 1)
	{
		printf("%d %d\n", a, c);
	}
	else
	{
		HanoiTowerMove(n - 1, a, c, b);
		printf("%d %d\n", a, c); 
		HanoiTowerMove(n - 1, b, a, c);
	}
}

int main()
{
	char data[50] = {' ',};				//하노이탑 개수 계산시 n=31을 넘어가는 순간 int 범위를 넘어간다. 따라서 이 숫자를 문자로 취급하자!
	int n;
	int i, j, tmp, cnt = 0;
	char ctmp;

	scanf_s("%d", &n);
	
	data[0] = '1';
	for (i = 1; i <= n; i++)
	{
		tmp = 0;
		for (j = cnt; j >= 0; j--)
		{
			tmp += (data[j] - '0') * 2;
			data[j] = tmp % 10 + '0';
			tmp /= 10;
		}
		if (tmp>0)
		{
			ctmp = tmp + '0';
			cnt++;
			for (j = cnt; j >= 1; j--)
			{
				data[j] = data[j - 1];
			}
			data[0] = ctmp;
		}
	}
	data[cnt]--;

	printf("%s\n", data);
	

	if (n <= 20)
	{
		HanoiTowerMove(n, 1, 2, 3);
	}

	return 0;
}
//상