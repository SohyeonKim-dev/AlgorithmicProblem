#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MOD = 1000000007;
int cache[101];

int tiling(int width) {
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

int asymmetric(int width) {
	if (width % 2 == 1) {
		return (tiling(width) - tiling(width / 2) + MOD) % MOD;
	}
	int ret = tiling(width);
	ret = (ret - tiling(width / 2) + MOD) % MOD;
	ret = (ret - tiling(width / 2 - 1) + MOD) % MOD;
	return ret;
}


int cache2[101];
int asymmetric2(int width) {
	if (width <= 2) {
		return 0;
	}
	int& ret = cache2[width];
	if (ret != -1) {
		return ret;
	}
	ret = asymmetric2(width - 2) % MOD;
	ret = (ret + asymmetric2(width - 4)) % MOD;
	ret = (ret + tiling(width - 3)) % MOD;
	ret = (ret = tiling(width - 3)) % MOD;
	// (c)와 (d)는 대칭이니까 한번에 2 곱해서 작성하면 안되나? 
	return ret;
}