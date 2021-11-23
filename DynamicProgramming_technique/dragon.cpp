#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;



// �巡�� Ŀ�� ���ڿ��� �����ϴ� ��� ȣ�� �˰��� 

void curve(const string& seed, int generations) {
	if (generations == 0) {
		cout << seed;
		return;
		// ���� ��� ó��
	}

	for (int i = 0; i < seed.size(); ++i) {
		if (seed[i] == 'X') {
			curve("X+YF", generations - 1);
		}
		else if (seed[i] == 'Y') {
			curve("FX-Y", generations - 1);
		}
		else {
			cout << seed[i];
		}
	}
}



// �巡�� Ŀ�� ������ �ذ��ϴ� �˰��� 

const int MAX = 1000000000 + 1;
int length[51];
void precalc() {
	length[0] = 1;
	for (int i = 1; i < 50; ++i) {
		length[i] = min(MAX, length[i - 1] * 2 + 2);
	}
}

const string EXPAND_X = "X+YF";
const string EXPAND_Y = "FX_Y";


char expand(const string& dragonCurve, int generations, int skip) {
	if (generations == 0) {
		assert(skip < dragonCurve.size());
		return dragonCurve[skip];
	}

	for (int i = 0; i < dragonCurve.size(); ++i) {
		if (dragonCurve[i] == 'X' || dragonCurve[i] == 'Y') {
			if (skip >= length[generations]) {
				skip -= length[generations];
			}
			else if (dragonCurve[i] == 'X') {
				return expand(EXPAND_X, generations - 1, skip);
			}
			else {
				return expand(EXPAND_Y, generations - 1, skip);
			}
		}

		else if (skip > 0) {
			--skip;
		}
		else {
			return dragonCurve[i];
		}
	}
	return '#';
}