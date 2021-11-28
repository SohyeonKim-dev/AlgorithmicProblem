#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


/*

- canWin(board) : 
�������� ���� board�� ��, �̹� ������ ����� 
�̱� �� �ִٸ� 1,
��� �� �ִٸ� 0,
�� �� �ۿ� ���ٸ� -1�� ��ȯ�Ѵ�.

+ board�� ��ȩ �ڸ��� 3������ ����.

- �Լ��� ��ȯ �� �� -1�� �����Ƿ�,
cache[]�� -2�� �ʱ�ȭ�ؾ��Ѵ�. 

- canWin()�� ���� ������ ��Ȳ�� ���Ҿ� ���� ���������� turn���� �����Ѵ�. 

- canWin()�� ��� ���� �õ��ϸ�, ��ȯ �� �� ���� ���� ���� ã�´�. 
: � ���� �ξ��� ��, -1�� ��ȯ�ȴٸ� ���� �̱� �� �ִٴ� ���̰�
  -1 ���� 0�� �ִٸ� 0�� �ִٸ� ��� �� �ִٴ� ���̴�. 

*/



bool isFinished(const vector<string>& board, char turn);
// turn�� �� ���� ��������� Ȯ���Ѵ�.


/*

bijection (���ܻ� �Լ�)
: �� ���� ���̸� �ߺ� ���� ��� �ϴ��Ϸ� ������Ű�� �Լ�, �ϴ��� ����.
: ������(board)�� �־����� ��, [0 ~ 19682 ~=3^9 ] ������ ������ ��ȯ�Ѵ�. 

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
	// board ��� ��ȯ�� �ֱ� ������, const ����X

	if (isFinished(board, 'o' + 'x' - turn) == true ) {
		return -1;
		// �������: �������� ��밡 �ξ� �� ���� ������� ��� -> -1 ��ȯ
		// ���� x�̸� input parameter�� o, ���� o�̸� input parameter�� x! 
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
				// �ٽ� �ǵ��� ���� ����!
			}
		}
	}

	if (minValue == 2 || minValue == 0) {
		return ret = -minValue;
		// �÷��� �� �� ���ų�, ���� ���� �ּ��� ��� 
		// ��밡 �̱�� �� -> ���� ���� ��
	}
}