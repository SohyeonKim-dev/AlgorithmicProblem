#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// 블록의 각 회전된 형태를 상대 좌표의 목록으로 저장해둔다.
vector < vector<pair<int, int>>> rotations;
int blockSize;



// 2차원 배열 arr를 시계 방향으로 90도 회전한 결과를 반환한다.
// 모든 칸에 대하여 이동을 실행해야 하므로 i & j 이중 반복문 사용
vector<string> rotate(const vector <string>& arr) {
	vector<string> ret(arr[0].size(), string(arr.size(), ' '));
	for (int i = 0; i < arr.size(); ++i) {
		for (int j = 0; j < arr[0].size(); ++j) {
			ret[j][arr.size() - i - 1] = arr[i][j];
		}
	}
	return ret;
}



// 블록의 4가지 회전 형태를 만들고, 이를 상대 좌표의 목록으로 변환함
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
					// 각 칸의 위치를 원점으로부터의 상대 좌표로 표현한다. 
					rotations[rot].push_back(make_pair(i - originY, j - originX));
				}
			}
		}
		// 블록을 시계방향으로 90도 회전한다. 
		block = rotate(block);
	}

	sort(rotations.begin(), rotations.end());
	rotations.erase(unique(rotations.begin(), rotations.end()), rotations.end());
	// 4가지 회전 형태 중 중복인 경우를 제거한다. (unique의 역할?!)
	blockSize = rotations[0].size();
	// 블록이 몇 칸 짜리인지 저장해 둔다.
}
