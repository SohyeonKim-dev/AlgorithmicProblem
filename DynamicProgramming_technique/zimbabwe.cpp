#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// ���ٺ��� ��� ������ ã�ƺ���!
// ���ٺ��� ������ ���� ��� ã�� ���� Ž�� �˰���

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
		if (!taken[i] && (i == 0 || digits[i - 1] != digits[i] || taken[i - 1])) {
			taken[i] = true;
			generate(price + digits[i], taken);
			taken[i] = false;
		}
	}
}



// ���ٺ��� ������ �ذ��ϴ� ���� ��ȹ�� �˰��� 

const int MOD = 1000000007;
string e;
string digits;
int n;
int m;
int cache[1 << 14][20][2];

int price(int index, int taken, int mod, int less) {
	if (index == n) {
		return (less && mod == 0) ? 1 : 0;
	}

	int& ret = cache[taken][mod][less];
	if (ret != -1) {
		return ret;
	}

	ret = 0;
	for (int next = 0; next < n; ++next) {
		if ((taken & (1 << next)) == 0) {
			if (!less && e[index] < digits[next]) {
				continue;
			}
			if (next > 0 && digits[next - 1] == digits[next] && (taken & (1 << (next - 1))) == 0) {
				continue;
			}
			int nextTaken = taken | (1 << next);
			int nextMod = (mod * 10 + digits[next] - '0') % m;
			int nextLess = less || e[index] > digits[next];
			ret += price(index + 1, nextTaken, nextMod, nextLess);
			ret %= MOD;
		}
	}
	return ret;
}

