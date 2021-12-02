#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


/*

결정 문제 : 정렬되어 있는 locations 중 cameras를 선택해 모든 카메라 간격이 
gap 이상이 되는 방법이 있는지를 반환한다. 
(최적화 문제를 범위를 지닌 결정 문제로 변환하여 해결하는 문제 해결 방법)

+ 카메라를 설치할 수 있는 지점마다, 모두 설치하는 탐욕적 방법 사용! 

*/
bool decision(const vector <double> & location, int cameras, double gap) {
	double limit = -1;
	int installed = 0;
	for (int i = 0; i < location.size(), ++i) {
		if (limit <= location[i]) {
			++installed;
			limit = location[i] + gap;
			// location[i] + gap 이후는 되어야 카메라 설치가 가능하다. 
		}
	}
	return installed >= cameras;
	// 결과적으로 cameras 대 이상 설치했다면 성공! 
}




/*

2nd : 최적화 문제
정렬되어 있는 locations 중 cameras를 선택해 최소 간격을 최대화한다.
1st 그냥 최적화 문제만 있는 것과는 별개의 개별 문제이다! :)

*/

double optimize(const vector <double>& location, int cameras) {
	double lo = 0;
	double hi = 241;

	for (int it = 0; it < 100; ++it) {
		double mid = (lo + hi) / 2.0;
		if (decision(location, cameras, mid)) {
			lo = mid;
		}
		else {
			hi = mid;
		}
	}
	return lo;
}