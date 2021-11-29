#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int order(const vector<int>& russian, const vector<int>& korean) {
	int n = russian.size();
	int wins = 0;

	multiset <int> ratings(korean.begin(), korean.end());

}