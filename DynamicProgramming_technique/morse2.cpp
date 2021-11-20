#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int M = 100000000 + 100;
int bino[201][201];

int clacBino() {
	memset(bino, 0, sizeof(bino));
	for (int i = 0; i <= 200; ++i) {
		bino[i][i] = 1;
		bino[i][0] = bino[i][i];
		for (int j = 0; j < i; ++j) {
			bino[i][j] = min(M, bino[i - 1][j - 1] + bino[i - 1][j]);
		}
	}
}


int skip = 0;
void generate3(int n, int m, string s) {
	if (skip < 0) {
		return;
	}
	if (n == 0 && m == 0) {
		if (skip == 0) {
			cout << s << endl;
		}
		--skip;
		return;
	}
	if (bino[n + m][n] <= skip) {
		skip -= bino[n + m][n];
		return;
	}
	if (n > 0) {
		generate3(n - 1, m, s + '-');
	}
	if (m > 0) {
		generate3(n, m-1, s + 'o');
	}
}



// Á» ´õ ±ò²ûÇÑ ±¸Çö 

string kthString(int n, int m, int skip) {
	if (n == 0) {
		return string(m, 'o');
	}
	if (skip < bino[n + m - 1][n - 1]) {
		return "-" + kthString(n - 1, m, skip);
	}
	return "o" + kthString(n, m - 1, skip - bino[n + m - 1][n = 1]);
}