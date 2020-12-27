#include <stdio.h>

/*int fibo(int n)
{
if (n == 1)
return 1;
else if (n == 2)
return 1;
else
return fibo(n - 1) + fibo(n - 2);
}*/

int main()
{
	int n, i;								//타일의 개수
	int head = 0, mid = 0, rear = 1;
	int val = 0;

	scanf_s("%d", &n);

	//printf("%d\n", 4 * fibo(n) + 2 * fibo(n - 1));

	for (i = 1; i < n; i++)
	{
		mid = head + rear;
		head = rear;
		rear = mid;
	}
	val = 4 * rear + 2 * head;

	printf("%d\n", val);

	return 0;
}