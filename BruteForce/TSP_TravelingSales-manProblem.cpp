// �����ϴ� ���ǿ� ���� (TSP)

#include <iostream>
#include <vector>

#define MAX		9876
using namespace std;

int numberofCity;
double dist[MAX][MAX]; // �� ���� ���� �Ÿ��� ��ȯ�ϴ� �迭 



// path: ���ݱ��� ���� ��� (1���� ���� for ������ ����!)
// visited: �� ������ �湮 ���� (boolean)
// currentLength: ���ݱ��� ���� ����� ����
// ������ ���õ��� �湮�ϴ� ��� �� ���� ª�� ���� ���̸� ��ȯ�Ѵ�. 

double shortestPath(vector<int>& path, vector<bool>& visited, double currentLength) {

	// ���� ���: ��� ���ø� �湮���� ������ ���� ���÷� ���ư��� and ����.
	if (path.size() == numberofCity) {
		return currentLength + dist[path[0]][path.back()];
	}

	double ret = MAX; // �ſ� ū ������ �ʱ�ȭ

	// ���� �湮�� ���ÿ� ���� ���� Ž��
	for (int next = 0; next < numberofCity; ++next) {
		if (visited[next] == true) {
			continue;
		}
		int here = path.back();
		path.push_back(next);
		visited[next] = true;

		//������ ��ε��� ��� ȣ��� �ϼ�, ���� ª�� ����� ���̸� ã��
		double shortestDist = shortestPath(path, visited, currentLength + dist[here][next]); // ��� ȣ��
		ret = min(ret, shortestDist);
		visited[next] = false; //�̰� ó������ ���ư��ٴ� ����?
		path.pop_back();
	}
	return ret;
}

int main() {

}