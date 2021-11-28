#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


/*

- canWin(board) : 
게임판이 현재 board일 때, 이번 차례인 사람이 
이길 수 있다면 1,
비길 수 있다면 0,
질 수 밖에 없다면 -1을 반환한다.

+ board를 아홉 자리의 3진수로 본다.

- 함수의 반환 값 중 -1이 있으므로,
cache[]를 -2로 초기화해야한다. 

- canWin()에 현재 게임판 상황과 더불어 누구 차례인지를 turn으로 전달한다. 

- canWin()은 모든 수를 시도하며, 반환 값 중 가장 작은 것을 찾는다. 
: 어떤 수를 두었을 때, -1이 반환된다면 내가 이길 수 있다는 뜻이고
  -1 없이 0이 있다면 0이 있다면 비길 수 있다는 뜻이다. 

*/



bool isFinished(const vector<string>& board, char turn);
// turn이 한 줄을 만들었는지 확인한다.


/*

bijection (전단사 함수)
: 두 집합 사이를 중복 없이 모두 일대일로 대응시키는 함수, 일대일 대응.
: 게임판(board)가 주어졌을 때, [0 ~ 19682 ~=3^9 ] 범위의 정수로 변환한다. 

*/

int bijection(const vector <string>&board) {
	int ret = 0;
	for (int y = 0; y < 3; ++y) {
		for (int x = 0; x < 3; ++x) {
			ret = ret * 3;
			if (board[y][x] == 'o') {
				++ret;
			}
			else if (board[y][x] == 'x') {
				ret += 2;
			}
		}
	}
	return ret;
}


 
int cache[19683];
int canWin(vector<string>& board, char turn) {
	// board 요소 변환이 있기 때문에, const 선언X

	if (isFinished(board, 'o' + 'x' - turn) == true ) {
		return -1;
		// 기저사례: 마지막에 상대가 두어 한 줄이 만들어진 경우 -> -1 반환
		// 내가 x이면 input parameter이 o, 내가 o이면 input parameter이 x! 
	}

	int& ret = cache[bijection(board)];
	if (ret != -2) {
		return ret;
	}

	int minValue = 2;
	for (int y = 0; y < 3; ++y) {
		for (int x = 0; x < 3; ++x) {
			if (board[y][x] == '.') {
				board[y][x] = turn;
				minValue = min(minValue, canWin(board, 'o' + 'x' - turn));
				board[y][x] = '.';
				// 다시 되돌려 놓는 과정!
			}
		}
	}

	if (minValue == 2 || minValue == 0) {
		return ret = -minValue;
		// 플레이 할 수 없거나, 비기는 것이 최선인 경우 
		// 상대가 이기는 것 -> 내가 지는 것
	}
}