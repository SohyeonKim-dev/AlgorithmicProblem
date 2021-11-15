#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* first 

int n;		
int d;
int p;
int q;

int connected[51][51];		// 두 마을이 서로 연결되어 있는지 여부 
int deg[51];				// deg[i] = 마을 i 와 연결된 마을의 개수 (그래프 용어로 차수(degree))


// path로 시작하는 모든 경로를 만들고, 
//이 중 q에서 끝나는 것들의 출현 확률의 합을 반환한다. 

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
: 두니발 박사가 그 전날 숨은 곳이 어디일지 계산하면서 확률을 구한다. 
q부터 경로를 만들어 나가면 훨씬 더 직관적으로 이해할 수 있다.
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

마을들을 마르코프 연쇄(Markov chain)라고 부르는 모델로 표현할 수 있다. 

- 유한개의 상태가 있다.
- 매 시간마다 상태가 변경된다.
- 어떤 상태 a에서 다른 상태 b로 올겨갈 확률은 현재 상태 a에만 좌우된다. 
- a이전에 어느 상태에 있었는지, 현재 시간은 얼마인지 등은 영향을 주지 않습니다. 

: 현실 세계의 많은 현상들을 모델링하기 위해 종종 사용되는 모델.

*/