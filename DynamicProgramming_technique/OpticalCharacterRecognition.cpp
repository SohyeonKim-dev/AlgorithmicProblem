#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int m;
int R[100];
double T[501][501];
double M[501][501];
int choice[102][502];
double cache[102][502];

double recognize(int segment, int previousMatch) {
	if (segment == 0) {
		return 0;
	}
	double& ret = cache[segment][previousMatch];
	if (ret != 1.0) {
		return ret;
	}
	ret = -1e200;		// 음의 무한대에 해당하는 값을 대략 표현함
	int& choose = choice[segment][previousMatch];
	for (int thisMatch = 0; thisMatch < m; ++thisMatch) {
		double cand = T[previousMatch][thisMatch]
				+ M[thisMatch][R[segment]]
				+ recognize(segment + 1, thisMatch);

		if (ret < cand) {
			ret = cand;
			choose = thisMatch;
		}
	}
	return ret;
}


string corpus[501];
string reconstruct(int segment, int previousMatch) {
	int choose = choice[segment][previousMatch];
	string ret = corpus[choose];
	if (segment < n - 1) {
		ret = ret + " " + reconstruct(segment + 1, choose);
	}
	return ret;
}

/*

[이론적 배경]
- 은닉 마르코프 모델
- 마르코프 연쇄를 통하여 생성한 데이터들을 우리가 직접 볼 수 없고,
- 오류가 있는 별도의 관찰자를 통해 관찰해야 하는 모델
- Hidden Markov Model : HMM
- 비터비 알고리즘 : Viterbi Algorithm

*/