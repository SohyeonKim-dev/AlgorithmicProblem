#include <iostream>

//wrongSolution

int n; // �л��� ��
bool areFriends[10][10]; // ���� ģ������ 2���� �迭�� ǥ��

int countPairings(bool taken[10]) { // taken[i] => i��° �ְ� ¦���� ã�Ҵ°�? 

	bool finished = true; // ��� ȣ���� ���� ���: �� ģ���� ã�Ҵٸ� �����϶�
	
	for (int i = 0; i < n; ++i) {
		if (taken[i] != true) { // ģ���� ���� �ְ� �ִٸ� ���� ������ �ʾҴ�! (��� �ݺ� ȣ���� ����)
			finished = false;
		}
	}

	if (finished == true) {
		return 1; // ������ ó��
	}

	int ret = 0;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (taken[i] != true && taken[j] != true && areFriends[i][j] == true) { 
				// i�� j�� ���� ¦�� ������, ���� ģ�ϴ�! -> ģ���� ������.

				taken[i] = true;
				taken[j] = true;
				ret += countPairings(taken);
				taken[i] = false; 
				taken[j] = false; // ��� ȣ�� ������ ó�� (why?)
			}
		}
	}
	return ret; // ���� �� �̻��ѵ�? 
}


// rightSolution

int countingPairings(bool taken[10]) { // 10���� �迭�� ¦ ���� �Ǵ� 
	int firstFree = -1;

	for (int i = 0; i < n; ++i) { // �� �� ���̺��� ģ���� ã�´�. 
		if (taken[i] != true) {
			firstFree = i;
			break;
		}
	}

	if (firstFree == -1) {
		return 1;
	}

	int ret = 0;

	for (int pairWith = firstFree + 1; pairWith < n; ++pairWith) {
		if (taken[pairWith] != true && areFriends[firstFree][pairWith]) {
			// i��° ����(firstFree)�� ¦�� ����, �� ������ ��(pairwith)�� ģ���̸鼭 ¦�� ���� ��

			taken[firstFree] = true;
			taken[pairWith] = true;
			ret += countingPairings(taken); // ��� ȣ��
			taken[firstFree] = false;
			taken[pairWith] = false;
		}
	}
	return ret;
}


int main() {

}