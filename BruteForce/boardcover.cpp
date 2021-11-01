#include <iostream>
#include <vector>

using namespace std;

const int coverType[4][3][2] = {
	{{0,0}, {1,0},{0,1}},
	{{0,0}, {0,1},{1,1}},
	{{0,0}, {1,0},{1,1}},
	{{0,0}, {1,0},{1,-1}},
};

bool set(vector <vector<int>> & board, int y, int x, int type, int delta) {
	bool ok = true;
}