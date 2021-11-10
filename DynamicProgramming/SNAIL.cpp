#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_N	9876

int n = 0;
int m = 0;
int cache [MAX_N] [2 * MAX_N + 1];

int climb(int days, int climbed) {
	if (days == m) {
		return climbed >= n ? 1 : 0;
	}

	int& ret = cache[days][climbed];
	if (ret != -1) {
		return ret;
	}
	
	ret = climb(days + 1, climbed + 1) + climb(days + 1, climbed + 2);
	return ret;
}


// �帶�� ã�ƿԴ�!
// ���� �帶�� ���� �� �� Ȯ���� 50% -> 75%

int climb2(int days, int climbed) {
	if (days == m) {
		return climbed >= n ? 1 : 0;
	}

	int& ret = cache[days][climbed];
	if (ret != -1) {
		return ret;
	}

	ret = 0.25*climb2(days + 1, climbed + 1) + 0.75*climb2(days + 1, climbed + 2);
	return ret; // ����� ���� �ƴ�, Ȯ���� return �Ѵ�. 
}
