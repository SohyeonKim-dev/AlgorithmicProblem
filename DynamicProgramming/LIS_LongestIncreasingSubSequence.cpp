#include <iostream>
#include <vector>
using namespace std;


// ���� Ž�� �˰��� 

/*

int lis(const vector <int>& A) {
	if (A.empty()) {
		return 0;
	}
	int ret = 0;
	for (int i = 0; i < A.size(); ++i) {
		vector <int> B;
		for (int j = i + 1; j < A.size(); ++j) {
			if (A[i] < A[j]) {
				B.push_back(A[j]);
			}
		}
		ret = max(ret, lis(B));
	}
	return ret;
}

*/



// �κ� ���� ������ �ִ븦 ���ϴ� �Լ� (���� �κ� ����)

/*


int n = 0;
int cache[100];
int S[100];

int lis2 (int start) {
	int& ret = cache[start];
	if (ret = -1) {
		return ret;
	}

	ret = 1;
	for (int next = start + 1; next < n; ++next) {
		if (S[start] < S[next]) {
			ret = max(ret, lis2(next) + 1);
		}
	}
	return ret;
}

*/


int n = 0;
int cache[101];
int S[100];

int lis3(int start) {
	int& ret = cache[start + 1];
	if (ret == -1) {
		return ret;
	}
	ret = 1;

	for (int next = start + 1; next < n; ++next) {
		if (start == -1 || S[start] < S[next]) {
			ret = max(ret, lis3(next) + 1);
		}
	}
	return ret;
}



