#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*


	[숫자 게임 문제]

n개의 정수를 일렬로 늘어놓은 게임판을 가지고 현우와 서하가 게임을 합니다.
게임은 현우부터 시작해서 번갈아가며 진행하며,
각 참가자는 자기 차례마다 두 가지 일 중 하나를 할 수 있습니다.

게임판의 왼쪽 끝에 있는 숫자나 오른쪽 끝에 있는 숫자 중 하나를 택해 가져갑니다.
가져간 숫자는 게임판에서 지워집니다.
게임판에 두 개 이상의 숫자가 있을 경우, 왼쪽 끝에서 2개, 혹은 오른쪽 끝에서 2개를 지웁니다.
게임은 모든 숫자가 다 없어졌을 때 끝나며,
각 사람의 점수는 자신이 가져간 숫자들의 합입니다.

현우와 서하는 점수가 더 낮은 쪽이 점수 높은 쪽에 한 점 차이마다 백 원씩 주기로 내기를 했습니다.
두 사람 모두 최선을 다할 때, 두 사람의 최종 점수 차이는 얼마일까요?


*/



/*

play(state) : 현재 게임판에 남은 수들이 state일 때,
(이번 차례인 참가자의 점수 - 다른 참가자의 점수)의 최대치

board[] : 게임판의 각 수를 저장하는 배열

- 반환 값이 -1도 가능하기 때문에, 
아직 계산되지 않은 EMPTY 값을 -987654321로 설정한다. 

*/




const int EMPTY = -987654321;
int n;
int board[50];
int cache[50][50];

int play(int left, int right) {
	if (left > right) {
		return 0;
		// 기저 사례
	}

	int& ret = cache[left][right];
	// 메모이제이션

	if (ret != EMPTY) {
		return ret;
	}

	// 수를 가져가는 경우
	ret = max(
		board[left] - play(left + 1, right),
		board[right] - play(left, right-1)
		// 내가 원하는 값을 구하고 싶다면 앞뒤의 play 값에 -를 취하면 된다.
		);

	//수를 제거하는 경우
	if (right - left + 1 >= 2) {
		ret = max(ret, -play(left + 2, right)); 
		// 왼쪽 두 개 삭제
		ret = max(ret, -play(left, right - 2));
		// 오른쪽 두 개 삭제
		// 인덱스의 2칸 이동으로 삭제하는 과정을 표현한다.
	}
	return ret;
}