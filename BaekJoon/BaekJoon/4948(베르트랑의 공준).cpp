#include <stdio.h>

#define maxn 246912
int t;

bool is_not_prime[maxn + 1] = { true,true,false };
int psum[maxn + 1];

int main() {
	for (int i = 2; i <= maxn; ++i) {
		if (is_not_prime[i])
			continue;
		for (int j = i + i; j <= maxn; j += i)
			is_not_prime[j] = true;
	}

	for (int i = 2; i <= maxn; ++i) {
		psum[i] = psum[i - 1];
		if (!is_not_prime[i])
			psum[i]++;
	}

	while (1) {
		scanf("%d", &t);
		if (t == 0)
			break;

		printf("%d\n", psum[t * 2] - psum[t]);
	}

	return 0;
}
