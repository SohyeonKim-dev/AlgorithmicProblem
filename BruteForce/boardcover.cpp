#include <iostream>
#include <vector>

using namespace std;

// �� ĭ�� ���� 4���� ����� ������ �迭
// ������ �Ʒ���, ���ʿ��� ���������� ������ ���⼺�� �ο��Ͽ��⿡ ������. 
const int coverType[4][3][2] = {
	{{0,0}, {1,0},{0,1}},
	{{0,0}, {0,1},{1,1}},
	{{0,0}, {1,0},{1,1}},
	{{0,0}, {1,0},{1,-1}},
};

// delta�� ���� ����� ���ų� ������
// �ش� ��ġ��(��ǥ) ��� ���� �� �ִ����� �Ǻ���
// type���� �ռ� �迭 ��ҷμ� 4������ ������. 
bool set(vector <vector<int>> & board, int y, int x, int type, int delta) {
	bool ok = true;
	for (int i = 0; i < 3; ++i) {
		const int ny = y + coverType[type][i][0];
		const int nx = x + coverType[type][i][1];

		if (ny < 0 || ny >= board.size() || nx < 0 || nx >= board.size()) {
			ok = false; // �⺻���� ���� ���� ����X
		}
		else if ((board[ny][nx] += delta) > 1) {
			ok = false; // board[][]�� ���� 0 or 1�� ����
		}
	}
	return ok;
}


// board�� ��� �� ĭ�� ���� �� �ִ� ����� ���� ��ȯ�Ѵ�. 
// board[][]�� 1�̸� ���� ĭ or ���� ĭ(������ ���ִ� ��)
// board[][]�� 0�̸� ������ ���� ĭ.

int cover(vector<vector<int>>& board) {
	int y = -1;
	int x = -1;

	//���� ��/���ʿ� �ִ� and ����ִ� ĭ�� ã�´�. 
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
	for (int type = 0; type < 4; ++type) { // type�� 4���ϱ�. 
		// ���� �ش� type���� ä�� �� �ִٸ�, ���ȣ�� �Ѵ�. 
		if (set(board, y, x, type, 1) == true) {
			ret += cover(board);
		}
		set(board, y, x, type, -1); // ������ ����� ġ���. 
	}
	return ret;
}