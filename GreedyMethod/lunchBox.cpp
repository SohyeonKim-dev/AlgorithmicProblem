#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N = 9876;

int n;
int e[MAX_N];
int m[MAX_N];

int heat() {
	vector<pair<int, int> > order;
	for (int i = 0; i < n; ++i) {
		order.push_back(make_pair(-e[i], i));
	}
	sort(order.begin(), order.end());

	int ret = 0;
	int beginEat = 0;
	for (int i = 0; i < n; ++i) {
		int box = order[i].second;
		beginEat += m[box];
		ret = max(ret, beginEat + e[box]);
	}
	return ret;
}
