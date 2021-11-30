#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int order(const vector<int>& russian, const vector<int>& korean) {
	int n = russian.size();
	int wins = 0;

	multiset <int> ratings(korean.begin(), korean.end());
	for (int rus = 0; rus < n; ++rus) {
		if (*ratings.rbegin() < russian[rus]) {
			ratings.erase(ratings.begin());
		}
		else {
			ratings.erase(ratings.lower_bound(russian[rus]));
			++wins;
		}
	}
	return wins;
}