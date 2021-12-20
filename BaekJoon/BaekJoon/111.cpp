//#include <stdio.h>
//#include <string.h>
//
//void main()
//
//{
//
//	/*------------------------------------------*/
//
//	/*input num: 공의 개수입니다.*/
//
//	/*input string: 공의 처음 정렬된 상태입니다.*/
//
//	/*A: 정렬된 공을 나타내는 배열입니다.*/
//
//	/*------------------------------------------*/
//
//
//
//
//	int inputNum;
//
//	char inputString[500000];
//
//	char A[500000];
//
//
//
//
//	scanf_s("%d", &inputNum);
//
//	for (int i = 0; i < inputNum; i++)
//		scanf_s("%c", &inputString[i]);
//
//
//
//
//	for (int i = 0; i < inputNum; i++)
//		A[i] = inputString[i];
//
//	/*빨간 공을 얼마나 옮겨 정렬를 했는지 나타내는 수입니다.*/
//
//	int redMoveNum = 0;
//
//	/*해설에서 설명한 방법대로 빨간 공을 정렬합니다.*/
//
//	for (int i = inputNum - 1; i >= 0; i--)
//
//	{
//
//		if (A[i] == 'B')
//
//		{
//
//			char temp;
//
//			for (int j = i; j >= 0; j--)
//
//			{
//
//				if (A[j] == 'R')
//
//				{
//
//					temp = A[i];
//
//					A[i] = A[j];
//
//					A[j] = temp;
//
//					redMoveNum++;
//
//					break;
//
//				}
//
//			}
//
//		}
//
//	}
//
//
//
//
//	for (int i = 0; i < inputNum; i++)
//
//		A[i] = inputString[i];
//
//
//
//
//	int blueMoveNum = 0;
//
//
//
//
//	for (int i = inputNum - 1; i >= 0; i--)
//
//	{
//
//		if (A[i] == 'R')
//
//		{
//
//			char temp;
//
//			for (int j = i; j >= 0; j--)
//
//			{
//
//				if (A[j] == 'B')
//
//				{
//
//					temp = A[i];
//
//					A[i] = A[j];
//
//					A[j] = temp;
//
//					blueMoveNum++;
//
//					break;
//
//				}
//
//			}
//
//		}
//
//	}
//
//	/*더 적게 공을 옮긴 쪽을 출력합니다.*/
//
//	if (redMoveNum > blueMoveNum)
//
//		printf("%d\n", blueMoveNum);
//
//	else
//
//		printf("%d\n", redMoveNum);
//
//}

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

class Brick {
public:
	int A;              //단면적
	int W;              //무게
	int H;              //높이
	int idx;            //인덱스

	Brick() : A(0), W(0), H(0), idx(0) {}

	Brick(int a, int w, int h, int idx) : A(a), W(w), H(h), idx(idx) {}

	virtual ~Brick() = default;

	bool operator>(const Brick &b) const {
		return A > b.A;
	}
};

int N;
std::vector<Brick> bricks;

template<typename T>
std::vector<T> &
operator+(std::vector<T> &dest, std::vector<T> val) {
	for (auto &i : val)
		dest.push_back(i);
	return dest;
}

std::istream &
operator>>(std::istream &in, Brick &a) {
	std::cin >> a.A >> a.H >> a.W;
	return in;
}

int main() {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::cin >> N;

	bricks.resize(N);
	for (auto &i : bricks)
		std::cin >> i;
	for (int i = 0; i < N; i++)
		bricks[i].idx = i;

	auto f = bricks;

	std::sort(bricks.begin(), bricks.end(), [](Brick &a, Brick &b) {
		return a > b;
	});

	std::map<int, std::pair<int, std::vector<int>>> dp;
	for (int i = 0; i < N; i++)
		dp[i] = { bricks[i].H, {bricks[i].idx} };

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (bricks[i].W < f[dp[j].second.back()].W &&
				(dp[i].first < dp[j].first + bricks[i].H)) {
				dp[i] = { bricks[i].H + dp[j].first, dp[j].second + std::vector<int> {bricks[i].idx} };
			}
		}
	}

	std::vector<int> ans;

	for (int max = -1, i = 0; i < N; i++) {
		if (max < dp[i].first || (max == dp[i].first && ans.size() < dp[i].second.size())) {
			max = dp[i].first;
			ans = dp[i].second;
		}
	}

	std::cout << ans.size() << '\n';

	std::reverse(ans.begin(), ans.end());
	for (auto i : ans)
		std::cout << i + 1 << '\n';
}