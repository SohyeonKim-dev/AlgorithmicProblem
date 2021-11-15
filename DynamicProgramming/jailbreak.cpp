#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* first 

int n;		
int d;
int p;
int q;

int connected[51][51];		// �� ������ ���� ����Ǿ� �ִ��� ���� 
int deg[51];				// deg[i] = ���� i �� ����� ������ ���� (�׷��� ���� ����(degree))


// path�� �����ϴ� ��� ��θ� �����, 
//�� �� q���� ������ �͵��� ���� Ȯ���� ���� ��ȯ�Ѵ�. 

double search(vector<int>& path) {
	if (path.size()== d + 1) {
		if (path.back() != q) {
			return 0.0;
		}
	double ret = 0;
	for (int i = 0; i + 1 < path.size(); ++i) {
		ret /= deg[path[i]];
	}
	return ret;
	}
	double ret = 0;
	for (int there = 0; there < n; ++there) {
		if (connected[path.back()][there]) {
			path.push_back(there);
			ret += search(path);
			path.pop_back();
		}
	}
	return ret;
}

*/


/* second 

int n;
int d;
int p;
int q;

double cache[51][101];
int connected[51][51];		
int deg[51];

double search2(int here, int days) {
	if (days == d) {
		return (here == q ? 1.0 : 0.0);
	}
	double& ret = cache[here][days];
	if (ret > -0.5) {
		return ret;
	}
	ret = 0.0;
	for (int there = 0; there < n; ++there) {
		if (connected[here][there]) {
			ret += search2(there, days + 1) / deg[here];
		}
	}
	return ret;
}

*/


/* third 
: �δϹ� �ڻ簡 �� ���� ���� ���� ������� ����ϸ鼭 Ȯ���� ���Ѵ�. 
q���� ��θ� ����� ������ �ξ� �� ���������� ������ �� �ִ�.
*/

int n;
int d;
int p;
int q;

double cache[51][101];
int connected[51][51];
int deg[51];

double search3(int here, int days) {
	if (days == 0) {
		return (here == p ? 1.0 : 0.0);
	}
	double& ret = cache[here][days];
	if (ret > -0.5) {
		return ret;
	}
	for (int there = 0; there < n; ++there) {
		if (connected[here][there]) {
			ret += search3(there, days - 1) / deg[there];
		}
	}
	return ret;
}


/* 

�������� �������� ����(Markov chain)��� �θ��� �𵨷� ǥ���� �� �ִ�. 

- ���Ѱ��� ���°� �ִ�.
- �� �ð����� ���°� ����ȴ�.
- � ���� a���� �ٸ� ���� b�� �ðܰ� Ȯ���� ���� ���� a���� �¿�ȴ�. 
- a������ ��� ���¿� �־�����, ���� �ð��� ������ ���� ������ ���� �ʽ��ϴ�. 

: ���� ������ ���� ������� �𵨸��ϱ� ���� ���� ���Ǵ� ��.

*/