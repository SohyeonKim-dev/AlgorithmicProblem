#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



/*



int n;
int m;

vector<int> eaters[50];
// eaters[food] : food를 먹을 수 있는 친구들의 번호
int best;




// food: 이번에 고려해야 할 음식의 번호
// edible: 지금까지 고른 음식 중 i번째 친구가 먹을 수 있는 음식의 수
// chosen: 지금까지 고른 음식의 수

void slowSearch(int food, vector<int>& edible, int chosen) {
	if (chosen >= best) {
		return;
	}

	// 기저: 모든 친구가 음식을 먹을 수 있는 지 확인 and 최적해 도출
	if (food == m) {
		if (find(edible.begin(), edible.end(), 0) == edible.end()) {
			best = chosen;
		}
		return;
	}

	// food X
	slowSearch(food + 1, edible, chosen);
	for (int j = 0; j < eaters[food].size(); ++j) {
		edible[eaters[food][j]]++;
	}
	// food O
	slowSearch(food + 1, edible, chosen + 1);
	for (int j = 0; j < eaters[food].size(); ++j) {
		edible[eaters[food][j]]--;
	}
}

*/




int n;
int m;

vector<int> eaters[50];
vector<int> canEat[50];
// canEat[i] = i번째 친구가 먹을 수 있는 음식의 집합
// eaters[i] = i번 음식을 먹을 수 있는 친구들의 집합 

int best;


void search(vector<int>& edible, int chosen) {
	// 간단한 가지치기
	if (chosen >= best) {
		return;
	}
	// 아직 먹을 음식이 없는 첫번째 친구를 찾는다.
	int first = 0;
	while (first < n && edible[first] > 0) {
		++first;
	}
	// 모든 친구가 먹을 음식이 있을 경우 종료한다.
	if (first == n) {
		best = chosen;
		return;
	}

	// 이 친구가 먹을 음식을 찾을 경우 종료한다. 
	for (int i = 0; i < canEat[first].size(); ++i) {
		int food = canEat[first][i];
		for (int j = 0; j < eaters[food].size(); ++j) {
			edible[eaters[food][j]]++;
		}
		search(edible, chosen + 1);
		for (int j = 0; j < eaters[food].size(); ++j) {
			edible[eaters[food][j]]--;
		}
	}
}