#include <iostream>
#include <vector>

using namespace std;

// 한 칸을 덮는 4가지 방법을 구현한 배열
// 위에서 아래로, 왼쪽에서 오른쪽으로 진행의 방향성을 부여하였기에 가능함. 
const int coverType[4][3][2] = {
	{{0,0}, {1,0},{0,1}},
	{{0,0}, {0,1},{1,1}},
	{{0,0}, {1,0},{1,1}},
	{{0,0}, {1,0},{1,-1}},
};

// delta에 따라 블록을 놓거나 제거함
// 해당 위치에(좌표) 블록 놓을 수 있는지도 판별함
// type에는 앞선 배열 요소로서 4가지가 존재함. 
bool set(vector <vector<int>> & board, int y, int x, int type, int delta) {
	bool ok = true;
	for (int i = 0; i < 3; ++i) {
		const int ny = y + coverType[type][i][0];
		const int nx = x + coverType[type][i][1];

		if (ny < 0 || ny >= board.size() || nx < 0 || nx >= board.size()) {
			ok = false; // 기본적인 전제 조건 충족X
		}
		else if ((board[ny][nx] += delta) > 1) {
			ok = false; // board[][]의 값은 0 or 1만 가능
		}
	}
	return ok;
}


// board의 모든 빈 칸을 덮을 수 있는 방법의 수를 반환한다. 
// board[][]이 1이면 덮인 칸 or 검은 칸(그전에 차있는 값)
// board[][]이 0이면 덮이지 않은 칸.

int cover(vector<vector<int>>& board) {
	int y = -1;
	int x = -1;

	//가장 윗/왼쪽에 있는 and 비어있는 칸을 찾는다. 
	for (int i = 0; i < board.size(); ++i) {
		for (int j = 0; j < board[i].size(); ++j) {
			if (board[i][j] == 0){
				y = i; 
				x = j;
				break;
			} 
			if (y != -1) {
				break;
			}
		}
	}

	if (y == -1) {
		return 1;
	}
	int ret = 0;
	for (int type = 0; type < 4; ++type) { // type은 4개니까. 
		// 만약 해당 type으로 채울 수 있다면, 재귀호출 한다. 
		if (set(board, y, x, type, 1) == true) {
			ret += cover(board);
		}
		set(board, y, x, type, -1); // 덮었던 블록을 치운다. 
	}
	return ret;
}