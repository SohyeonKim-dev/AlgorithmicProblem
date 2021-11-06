#include <iostream>
#include <vector>
using namespace std;

int n = 0;
int triangle[100][100];
int cache[100][100];

int path(int y, int x) {
	if (y == n - 1) {
		return triangle[y][x];
	}

	//메모이제이션
	int& ret = cache[y][x];

	if (ret != -1) {
		return ret;
	}

	ret = max(path(y + 1, x), path(y + 1, x + 1) + triangle[y][x]);
	return ret;
}