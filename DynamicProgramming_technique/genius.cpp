#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>
using namespace std;



/*

	memset �Լ� : void* memset(void* ptr, int value, size_t num);

- ptr :�����ϰ��� �ϴ� �޸��� ���� �ּ� / �� �ּҸ� ����Ű�� �ִ� �����Ͱ� ��ġ�ϴ� �ڸ�
- value : �޸𸮿� �����ϰ��� �ϴ� �� 
- size_t num : ����Ʈ �����ν� �޸��� ũ�� ������ ������ ���� / ���� "���� * sizeof(������Ÿ��)" ���·� �ۼ�.


*/



struct SquareMatrix {
    int N;
    vector<vector<double> > v;
    SquareMatrix(int _N);
    ~SquareMatrix();
    static SquareMatrix identity(int N);
    SquareMatrix operator * (const SquareMatrix& rhs) const;
    SquareMatrix pow(int n) const;
    double* operator [] (int idx);
};

SquareMatrix::SquareMatrix(int _N) {
    N = _N;
    v.resize(N, vector<double>(N, 0));
}

SquareMatrix::~SquareMatrix() {
}

SquareMatrix SquareMatrix::identity(int N) {
    SquareMatrix ret = SquareMatrix(N);
    for (int i = 0; i < N; i++) ret.v[i][i] = 1;
    return ret;
}

SquareMatrix SquareMatrix::operator * (const SquareMatrix& rhs) const {
    assert(N == rhs.N);

    SquareMatrix ret = SquareMatrix(N);
    for (int k = 0; k < N; k++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                ret.v[i][j] += v[i][k] * rhs.v[k][j];
    return ret;
}

SquareMatrix SquareMatrix::pow(int n) const {
    if (n == 0) return identity(N);
    if (n % 2 > 0) return (*this) * pow(n - 1);
    SquareMatrix half = pow(n / 2);
    return half * half;
}

double* SquareMatrix::operator [] (int idx) {
    return &v[idx][0];
}

// SquareMatrix ��ó: https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=infoefficien&logNo=220079832226




int n;
int k;
int length[50];
double T[50][50];

vector<double> getprob1() {
	double c[5][50];
	memset(c, 0, sizeof(c));
	c[0][0] = 1.0;
	for (int time = 1; time <= k; ++time) {
		for (int song = 0; song < n; ++song) {
			double& prob = c[time % 5][song];
			prob = 0;
			for (int last = 0; last < n; ++last) {
				prob += c[(time - length[last] + 5) % 5][last] * T[last][song];
			}
		}
	}
	vector <double> ret(n);
	for (int song = 0; song < n; ++song) {
		for(int start = k; start < n; ++start) {
			ret[song] += c[start % 5][song];
		}
	}
	return ret;
}


vector <double> getProb2() {
	SquareMatrix W(4 * n);
    for (int i = 0; i < 3 * n; ++i) {
        W[i][i + 1] = 1.0;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            W[3 * n + 1][(4 - length[j]) * n + j] = T[j][i];
        }
    }
    SquareMatrix Wk = W.pow(k);
    vector<double> ret(n);

    for (int song = 0; song < n; ++song) {
        for (int start = 0; start < length[song]; ++start) {
            ret[song] = Wk[(3 - start) * n + song][3 * n];
        }
    }
    return ret;
}