#include <iostream>
#include <vector>

using namespace std;

const int INF = 9999;
const int SWITCHES = 10;
const int CLOCKS = 16;

// linked[i][j] -> i번째 시계와 j번째 시계가 연결되었으면 'x', 아니면 '.'
const char linked[SWITCHES][CLOCKS + 1] = {
	
	"xxx.............",
	"...x...x.x.x....",
	"....x.....x...xx",
	"x...xxxx........",
	"......xxx.x.x...",
	"x.x...........xx",
	"...x..........xx",
	"....xx.x......xx",
	".xxxxx..........",
	"...xxx...x...x.."
};


//모든 시계가 12시를 가리키는가?
bool areAligned(const vector<int>& clocks) { } ;

//switcH번째 스위치를 누른다. 
void push(vector<int> clocks, int switcH) {
	for (int clock = 0; clock < CLOCKS; ++clock) {
		if (linked[switcH][clock] == 'x') {
			clocks[clock] += 3; // 연결된 경우에, 해당 시계에 3을 더해줘야지
			if (clocks[clock] == 15) {
				clocks[clock] = 3; // 15 이상은 무의미하다. ==3. (3, 6, 9, 12)
			}
		}
	}
}

// clocks: 현재 시계들의 상태
// switcH: 이번에 누를 스위치의 번호
// 남은 스위치들을 눌러서, clocks를 12시로 맞출 수 있는 최소 횟수를 반환한다. 
// 만약 불가능하다면, INF 이상의 큰 수를 반환한다. 

int solve(vector<int>& clocks, int switcH) {
	if (switcH == SWITCHES) {

		if (areAligned(clocks) == true) {
			return 0; // 모두 12시를 가리키면 완료
		}
		else {
			return INF;
		}
	}
	

	int ret = INF;
	// 해당 스위치에 대하여 최대 3회 누르는 경우까지를 모두 시도(완전 탐색)
	for(int cnt = 0; cnt < 4; ++cnt) {
		ret = min(ret, cnt + solve(clocks, switcH + 1));
		push(clocks, switcH);
	}
	return ret;
}

