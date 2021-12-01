#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



/*



int n;
int m;

vector<int> eaters[50];
// eaters[food] : food�� ���� �� �ִ� ģ������ ��ȣ
int best;




// food: �̹��� ����ؾ� �� ������ ��ȣ
// edible: ���ݱ��� �� ���� �� i��° ģ���� ���� �� �ִ� ������ ��
// chosen: ���ݱ��� �� ������ ��

void slowSearch(int food, vector<int>& edible, int chosen) {
	if (chosen >= best) {
		return;
	}

	// ����: ��� ģ���� ������ ���� �� �ִ� �� Ȯ�� and ������ ����
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
// canEat[i] = i��° ģ���� ���� �� �ִ� ������ ����
// eaters[i] = i�� ������ ���� �� �ִ� ģ������ ���� 

int best;


void search(vector<int>& edible, int chosen) {
	// ������ ����ġ��
	if (chosen >= best) {
		return;
	}
	// ���� ���� ������ ���� ù��° ģ���� ã�´�.
	int first = 0;
	while (first < n && edible[first] > 0) {
		++first;
	}
	// ��� ģ���� ���� ������ ���� ��� �����Ѵ�.
	if (first == n) {
		best = chosen;
		return;
	}

	// �� ģ���� ���� ������ ã�� ��� �����Ѵ�. 
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