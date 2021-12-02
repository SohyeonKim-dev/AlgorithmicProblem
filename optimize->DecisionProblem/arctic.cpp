#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n;
// �� ���� ������ �Ÿ��� �̸� ����صд�. 
double dist[101][101];


// �Ÿ� d ������ �����鸸�� �������� ��,
// ��� ������ ����Ǵ��� ���θ� ��ȯ�Ѵ�. 

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



// ��� ������ ������ �� �ִ� �ּ����� d�� ��ȯ�Ѵ�.
double optimize() {
	double lo = 0;
	double hi = 1416.00;
	for (int it = 0; it < 100; ++it) {
		double mid = (lo + hi) / 2.0;
		if (decision(mid)) {
			// mid �� �����ϴٸ� �� ���� ���� ã�´�. 
			hi = mid;
		}
		else {
			lo = mid;
			// �ƴϸ�, �� ū(bad) ���� ã�´�. 
		}
	}
	return hi;
}