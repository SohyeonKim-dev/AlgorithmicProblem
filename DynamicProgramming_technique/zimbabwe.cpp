#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string e;
string digits;
int n;
int m;

void generate(string price, bool taken[15]) {
	if (price.size() == n) {
		if (price < e) {
			cout << price << endl;
		}
		return;
	}

	for (int i = 0; i < n; ++i) {

	}
}