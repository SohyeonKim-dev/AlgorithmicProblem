#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MOD = 1000000007;
int cache[101];

int tiling (int width) {
	if (width < 1) {
		return 1;
	}

	int& ret = cache[width];
	if (ret != -1) {
		return -1;
	}
	
	ret = (tiling(width - 1) + tiling(width - 1)) % MOD;
	return ret;
}