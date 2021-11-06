#include <iostream>
#include <vector>
using namespace std;

/*
* 
int n = 0;
int board[100][100];

bool jump(int y, int x) {
	if (y >= n || x >= n) {
		return false; // 여기서  걸러주기 때문에 아래 반환과 같은 점화식이 성립한다. 
	}
	if (y == n - 1 || x == n - 1) {
		return true;
	}
	int jumpSize = board[y][x];
	return jump(y + jumpSize, x) || jump(y, x + jumpSize);
}

*/

int n = 0;
int board[100][100];
int cache [100][100];

bool jump2(int y, int x) {

	if (y >= n || x >= n) {
		return 0;
	}
	if (y == n - 1 || x == n - 1) {
		return 1;
	}

	//메모이제이션
	int& ret = cache[y][x];
	if (ret != -1) {
		return ret;
	}

	int jumpSize = board[y][x];
	return ret = (jump2(y + jumpSize, x) || jump2(y, x + jumpSize));

}