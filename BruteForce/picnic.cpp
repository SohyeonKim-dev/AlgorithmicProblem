#include <iostream>

//wrongSolution

int n; // 학생의 수
bool areFriends[10][10]; // 서로 친구인지 2차원 배열로 표현

int countPairings(bool taken[10]) { // taken[i] => i번째 애가 짝꿍을 찾았는가? 

	bool finished = true; // 재귀 호출의 기저 사례: 다 친구를 찾았다면 종료하라
	
	for (int i = 0; i < n; ++i) {
		if (taken[i] != true) { // 친구가 없는 애가 있다면 아직 끝나지 않았다! (재귀 반복 호출의 조건)
			finished = false;
		}
	}

	if (finished == true) {
		return 1; // 기저의 처리
	}

	int ret = 0;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (taken[i] != true && taken[j] != true && areFriends[i][j] == true) { 
				// i와 j는 아직 짝이 없으나, 서로 친하다! -> 친구로 만들어라.

				taken[i] = true;
				taken[j] = true;
				ret += countPairings(taken);
				taken[i] = false; 
				taken[j] = false; // 재귀 호출 이후의 처리 (why?)
			}
		}
	}
	return ret; // 뭔가 좀 이상한데? 
}


// rightSolution

int countingPairings(bool taken[10]) { // 10개의 배열로 짝 여부 판단 
	int firstFree = -1;

	for (int i = 0; i < n; ++i) { // 앞 쪽 아이부터 친구를 찾는다. 
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
			// i번째 아이(firstFree)가 짝이 없고, 걔 이후의 애(pairwith)가 친구이면서 짝이 없을 때

			taken[firstFree] = true;
			taken[pairWith] = true;
			ret += countingPairings(taken); // 재귀 호출
			taken[firstFree] = false;
			taken[pairWith] = false;
		}
	}
	return ret;
}


int main() {

}