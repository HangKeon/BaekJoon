#include <iostream>
using namespace std;

int arr[] = { 1,9,3,8,4,5,5,9,10,3,4,5 };			//배열의 값 12개
int tree[4 * 12];									//arr의 크기 x 4 인 트리를 만든다.

//트리를 만들어 주는 함수
int init(int s, int e, int node)					//init(시작 인덱스, 끝 인덱스, 구하는 노드 번호)
{
	if (s == e)										//탈출 조건 -> 범위가 1인 리프 노드
		return tree[node] = arr[s];

	int mid = (s + e) / 2;

	//왼쪽 노드 + 오른쪽 노드를 재귀 함수를 통해 구해준다.
	return tree[node] = init(s, mid, node * 2) + init(mid + 1, e, node * 2 + 1);
}

int sum(int s, int e, int node, int l, int r)		//sum(시작 인덱스, 끝 인덱스, 구하는 노드 번호, 구간 합 범위)
{
	if (l > e || r < s)								//범위 밖에 있는 경우
		return 0;

	if (l <= s && e <= r)							//범위 안에 있는 경우
		return tree[node];

	//그렇지 않은 경우 두 부분으로 나누어 합을 구한다.
	int mid = (s + e) / 2;

	return sum(s, mid, node * 2, l, r) + sum(mid + 1, e, node * 2 + 1, l, r);
}

//update(시작 인덱스, 끝 인덱스, 구하는 노드 번호, 수정하려는 노드 번호, 수정할 값의 차이)
void update(int s, int e, int node, int idx, int val)	
{
	if (idx<s || idx>e)								//범위 밖에 있는 경우
		return;

	//범위 안에 있다면 내려가며 다른 원소도 갱신한다.

	tree[node] += val;								//구간 합 트리에 val을 더한다.

	if (s == e)										//탈출 조건 -> 범위가 1인 리프 노드
		return;

	//그렇지 않은 경우 두 부분으로 나누어 합을 구한다.
	int mid = (s + e) / 2;

	update(s, mid, node * 2, idx, val);				//왼쪽 자식 노드
	update(mid + 1, e, node * 2 + 1, idx, val);		//오른쪽 자식 노드
}

int main()
{
	init(0, 11, 1);									//구간 합 트리 생성

	//구간 합 구하기
	cout << "인덱스 0 ~ 11의 구간합 : " << sum(0, 11, 1, 0, 11) << endl;

	//구간 합 구하기
	cout << "인덱스 4 ~ 8의 구간합 : " << sum(0, 11, 1, 4, 8) << endl;

	//구간 합 갱신
	cout << "<인덱스 7의 원소를 1만큼 수정>" << endl;
	update(0, 11, 1, 7, 1);

	// 구간 합 구하기
	cout << "인덱스 6 ~ 11의 구간합 : " << sum(0, 11, 1, 6, 11) << endl;

	return 0;
}