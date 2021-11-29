#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


/*

int MAX_BUDGET = 12345;

int n;
int m;
int price[20];
int pref[20];

int cache[MAX_BUDGET];

int sushi(int budget) {
	int& ret = cache[budget];
	if (ret != -1) {
		return ret;
	}
	ret = 0;
	for (int dish = 0; dish < n; ++dish) {
		if (budget < price[dish]) {
			continue;
		}
		ret = max(ret, sushi(budget - price[dish]) + pref[dish]);
	}
	return ret;
}

*/




// �ݺ��� ���� ��ȹ�� �˰���

int n;
int m;
int price[20];
int pref[20];
int c[201];

int sushi3() {
	int ret = 0;
	c[0] = 0;
	for (int budget = 0; budget < m; ++budget) {
		int cand = 0;
		for (int dish = 0; dish < n; ++dish) {
			if (budget >= price[dish]) {
				cand = max(cand, c[(budget - price[dish])] + pref[dish]);
			}
		}
		c[budget % 201] = cand;
		ret = max(ret, cand);
	}
	return ret;
	// �ִ� �������� ���� ��ȯ�Ѵ�.
}
