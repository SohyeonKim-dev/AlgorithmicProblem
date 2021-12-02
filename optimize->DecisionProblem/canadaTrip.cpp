#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int k;
int l[5000];
int m[5000];
int g[5000];




// 결정 문제:
// dist 지점까지 가면서 k개 이상의 표지판을 만날 수 있는가?

bool decision(int dist) {
	int ret = 0;
	for (int i = 0; i < n; ++i) {
		// i번째 도시를 하나 이상 보게 되는가?
		if (dist >= l[i] - m[i]) {
			ret += (min(dist, l[i]) - (l[i]) - m[i]) / g[i] + 1;
		}
	}
	return ret >= k;
}




// k 번째 표지판을 만나는 지점의 위치를 (1개로, 정확히) 계산
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