#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n;
// 두 기지 사이의 거리를 미리 계산해둔다. 
double dist[101][101];


// 거리 d 이하인 기지들만을 연결했을 때,
// 모든 기지가 연결되는지 여부를 반환한다. 

bool decision(double d) {
	vector <bool> visited(n, false);
	visited[0] = true;
	queue<int> q;
	q.push(0);
	int seen = 0;

	while (!q.empty()) {
		int here = q.front();
		q.pop();
		++seen;
		for (int there = 0; there < n; ++there) {
			if (!visited[there] && dist[here][there] <= d) {
				visited[there] = true;
				q.push(there);
			}
		}
	}
	return seen == n;
}



// 모든 기지를 연결할 수 있는 최소한의 d를 반환한다.
double optimize() {
	double lo = 0;
	double hi = 1416.00;
	for (int it = 0; it < 100; ++it) {
		double mid = (lo + hi) / 2.0;
		if (decision(mid)) {
			// mid 가 가능하다면 더 좋은 답을 찾는다. 
			hi = mid;
		}
		else {
			lo = mid;
			// 아니면, 더 큰(bad) 답을 찾는다. 
		}
	}
	return hi;
}