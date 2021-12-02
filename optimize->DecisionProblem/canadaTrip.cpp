#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int k;
int l[5000];
int m[5000];
int g[5000];




// ���� ����:
// dist �������� ���鼭 k�� �̻��� ǥ������ ���� �� �ִ°�?

bool decision(int dist) {
	int ret = 0;
	for (int i = 0; i < n; ++i) {
		// i��° ���ø� �ϳ� �̻� ���� �Ǵ°�?
		if (dist >= l[i] - m[i]) {
			ret += (min(dist, l[i]) - (l[i]) - m[i]) / g[i] + 1;
		}
	}
	return ret >= k;
}




// k ��° ǥ������ ������ ������ ��ġ�� (1����, ��Ȯ��) ���
int optimize() {
	int lo = -1;
	int hi = 8030001;

	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		if (decision(mid)) {
			hi = mid;
		}
		else {
			lo = mid;
		}
	}
	return hi;
}