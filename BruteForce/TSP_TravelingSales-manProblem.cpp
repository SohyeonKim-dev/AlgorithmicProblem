// 여행하는 외판원 문제 (TSP)

#include <iostream>
#include <vector>

#define MAX		9876
using namespace std;

int numberofCity;
double dist[MAX][MAX]; // 두 도시 간의 거리를 반환하는 배열 



// path: 지금까지 만든 경로 (1차원 벡터 for 동적인 길이!)
// visited: 각 도시의 방문 여부 (boolean)
// currentLength: 지금까지 만든 경로의 길이
// 나머지 도시들을 방문하는 경로 중 가장 짧은 것의 길이를 반환한다. 

double shortestPath(vector<int>& path, vector<bool>& visited, double currentLength) {

	// 기저 사례: 모든 도시를 방문했을 때에는 시작 도시로 돌아가고 and 종료.
	if (path.size() == numberofCity) {
		return currentLength + dist[path[0]][path.back()];
	}

	double ret = MAX; // 매우 큰 값으로 초기화

	// 다음 방문할 도시에 대한 완전 탐색
	for (int next = 0; next < numberofCity; ++next) {
		if (visited[next] == true) {
			continue;
		}
		int here = path.back();
		path.push_back(next);
		visited[next] = true;

		//나머지 경로들을 재귀 호출로 완성, 가장 짧은 경로의 길이를 찾음
		double shortestDist = shortestPath(path, visited, currentLength + dist[here][next]); // 재귀 호출
		ret = min(ret, shortestDist);
		visited[next] = false; //이게 처음으로 돌아간다는 동작?
		path.pop_back();
	}
	return ret;
}

int main() {

}