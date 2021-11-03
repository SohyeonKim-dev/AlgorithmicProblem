#include <iostream>
#include <vector>

using namespace std;

const int INF = 9999;
const int SWITCHES = 10;
const int CLOCKS = 16;

// linked[i][j] -> i��° �ð�� j��° �ð谡 ����Ǿ����� 'x', �ƴϸ� '.'
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


//��� �ð谡 12�ø� ����Ű�°�?
bool areAligned(const vector<int>& clocks) { } ;

//switcH��° ����ġ�� ������. 
void push(vector<int> clocks, int switcH) {
	for (int clock = 0; clock < CLOCKS; ++clock) {
		if (linked[switcH][clock] == 'x') {
			clocks[clock] += 3; // ����� ��쿡, �ش� �ð迡 3�� ���������
			if (clocks[clock] == 15) {
				clocks[clock] = 3; // 15 �̻��� ���ǹ��ϴ�. ==3. (3, 6, 9, 12)
			}
		}
	}
}

// clocks: ���� �ð���� ����
// switcH: �̹��� ���� ����ġ�� ��ȣ
// ���� ����ġ���� ������, clocks�� 12�÷� ���� �� �ִ� �ּ� Ƚ���� ��ȯ�Ѵ�. 
// ���� �Ұ����ϴٸ�, INF �̻��� ū ���� ��ȯ�Ѵ�. 

int solve(vector<int>& clocks, int switcH) {
	if (switcH == SWITCHES) {

		if (areAligned(clocks) == true) {
			return 0; // ��� 12�ø� ����Ű�� �Ϸ�
		}
		else {
			return INF;
		}
	}
	

	int ret = INF;
	// �ش� ����ġ�� ���Ͽ� �ִ� 3ȸ ������ �������� ��� �õ�(���� Ž��)
	for(int cnt = 0; cnt < 4; ++cnt) {
		ret = min(ret, cnt + solve(clocks, switcH + 1));
		push(clocks, switcH);
	}
	return ret;
}

