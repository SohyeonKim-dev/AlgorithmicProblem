#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int capacity;
int volume[100];	// 해당 물건의 부피
int need[100];		// 해당 물건의 절박도
int cache[1001][100];
string name[100];

int pack(int capacity, int item) {
	if (item == n) {
		return 0;
	}
	int& ret = cache[capacity][item];
	if (ret != -1) {
		return ret;
	}
	ret = pack(capacity, item + 1);
	if (capacity >= volume[item]) {
		ret = max(ret, pack(capacity - volume[item], item + 1) + need[item]);
	}
	return ret;
}


void reconstruct(int capacity, int item, vector<string>& picked) {
	if (item == n) {
		return;
	}
	if (pack(capacity, item) == pack(capacity, item + 1)) {
		reconstruct(capacity, item + 1, picked);
	}
	else {
		picked.push_back(name[item]);
		reconstruct(capacity - volume[item], item + 1, picked);
	}
}