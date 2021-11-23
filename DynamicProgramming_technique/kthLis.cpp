#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 200000000 + 1;
int n;
int cacheLen[501];
int cacheCnt[501];
int S[500];


int n = 0;
int cache[101];
int S[100];

int lis(int start) {
	int& ret = cacheLen[start + 1];
	if (ret != -1) {
		return ret;
	}
	ret = 1;
}

int lis3(int start) {
	int& ret = cache[start + 1];
	if (ret == -1) {
		return ret;
	}
	ret = 1;

	for (int next = start + 1; next < n; ++next) {
		if (start == -1 || S[start] < S[next]) {
			ret = max(ret, lis3(next) + 1);
		}
	}
	return ret;
}

int count(int start) {
	if (lis(start) == 1) {
		return 1;
	}
	int& ret = cacheCnt[start + 1];
	if (ret != -1) {
		return ret;
	}
	ret = 0;
	for (int next = start + 1; next < n; ++next) {
		if ((start == -1 || S[start] < S[next]) && lis(start) == lis(next)+1) {
			ret = min <long long >(MAX, (long long)ret + count(next));
		}
	}
	return ret;
}



// º»°Ý KLIS



void reconstruct(int start, int skip, vector<int>& lis) {
	if (start != -1) {
		lis.push_back(S[start]);
	}
	vector<pair<int, int>> followers;

	for (int next = start + 1; next < n; ++next) {
		if ((start == -1 || S[start] < S[next]) && lis3(start) == lis3(next) + 1) {
			followers.push_back(make_pair(S[next], next));
		}
	}

	sort(followers.begin(), followers.end());

	for (int i = 0; i < followers.size(); ++i) {
		int idx = followers[i].second;
		int cnt = count(idx);
		if (cnt <= skip) {
			skip -= cnt;
		}
		else {
			reconstruct(idx, skip, lis);
			break;
		}
	}

}