#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int skip;

void generate2(int n, int m, string s) {
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
	if (n > 0) {
		generate2(n - 1, m, s + "-");
	}
	if (m > 0) {
		generate2(n - 1, m, s + "o");
	}

}