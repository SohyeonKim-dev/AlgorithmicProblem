#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector < vector<pair<int, int>>> rotations;
int blockSize;

vector<string> rotate(const vector <string>& arr) {
	vector<string> ret(arr[0].size(), string(arr.size(), ' '));
	for (int i = 0; i < arr.size(); ++i) {
		for (int j = 0; j < arr[0].size(); ++j) {
			ret[j][arr.size() - i - 1] = arr[i][j];
		}
	}
	return ret;
}

void generateRotations(vector<string> block) {
	rotations.clear();
	rotations.resize(4);

	for (int rot = 0; rot < 4; ++rot) {
		int originY = -1;
		int originX = -1;

		for (int i = 0; i < block.size(); ++i) {
			for (int j = 0; j < block[i].size(); ++j) {
				if (block[i][j] == '#') {
					if (originY == -1) {
						originY = i;
						originX = j;
					}
					rotations[rot].push_back(make_pair(i - originY, j - originX));
				}
			}
		}
		block = rotate(block);
	}
	sort(rotations.begin(), rotations.end());
	rotations.erase(unique(rotations.begin(), rotations.end()), rotations.end());
	blockSize = rotations[0].size();
}
