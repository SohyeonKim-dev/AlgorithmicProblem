#include <iostream>
#include <vector>
using namespace std;

bool match(const string& w, const string& s) {
	int pos = 0;
	while (pos < s.size() && pos < w.size() && w[pos] == '?'    || w[pos] == s[pos]) {
		++pos;
	}

	if (pos == w.size()) {
		return pos == s.size();
		// 같으면 true, 다르면 false
	}

	if (w[pos] == '*') {
		for (int skip = 0; pos + skip <= s.size(); ++skip) {
			if (match(w.substr(pos + 1), s.substr(pos + skip))) {
				return true;
			}
		}
	}
	return false;
}


// 비둘기집의 원리 -> 부분 문제

int cache[101][101];
string W;
string S;

bool matchMemoized(int w, int s) {
	int& ret = cache[w][s];

	if (ret != -1) {
		return ret;
	}

	while (s < S.size() && w < W.size() && W[w] == '?'    || W[w] == S[s]) {
		++w;
		++s;
	}

	if (w == W.size()) {
		ret = (s == S.size());
		return ret;
	}

	if (W[w] == '*') {
		for (int skip = 0; skip + s <= S.size(); ++skip) {
			if (matchMemoized(w + 1, s + skip)) {
				ret = 1;
				return ret;
			}
		}
	}
	return ret = 0;
}




// 다른 분해 방법

/*



while (s < S.size() && w < W.size() && W[w] == '?'      || W[w] == S[s]) {
	return ret = matchMemoized(w+1, s+1);
}

if (W[w] == '*') {
	if (matchMemoized(w+1, s) || s < S.size() && matchMemoized(w, s+1)){
		return ret = 1;
	}
}


*/
