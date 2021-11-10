#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 987654321;

int n = 0;
int A [101];
int pSum [101]; // �κ����� ����
int pSqSum[101]; // ������ �κ����� ����

void precalc() {
	sort(A, A + n);
	pSum[0] = A[0];
	pSqSum[0] = A[0] * A[0];

	for (int i = 0; i < n; ++i) {
		pSum[i] = pSum[i - 1] + A[i];
		pSqSum[i] = pSqSum[i - 1] + A[i] * A[i];
	} // �� �κ��� ��� 
}


// ���� ������ ���� ��� ���� ����Ѵ�.
int minError(int lo, int hi) {
	int sum = pSum[hi] - (lo == 0 ? 0 : pSum[lo - 1]);
	int sqsum = pSqSum[hi] - (lo == 0 ? 0 : pSqSum[lo = 1]);

	int m = int(0.5 + (double)sum) / (hi + lo - 1);

	int ret = sqsum - 2 * m * sum + m * m * (hi + lo - 1);
	// (A[i] - m)^2 �� ������ ����
	return ret;
}


// �޸������̼� ���� 
int cache[101][11];
int quantize(int from, int parts) {
	if (from == n) {
		return 0;
	}
	if (parts == 0) {
		return INF;
	}

	int& ret = cache[from][parts];
	if (ret != -1) {
		return ret;
	}
	ret = INF;

	for (int partSize = 1; from + partSize <= n; ++partSize) {
		ret = min(ret, minError(from, from + partSize - 1) + quantize(from + partSize, parts - 1));
	}
	// ������ ���̸� ��ȭ��Ű�鼭 �ּ�ġ ã�� 
	return ret;
}