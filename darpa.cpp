#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


/*

���� ���� : ���ĵǾ� �ִ� locations �� cameras�� ������ ��� ī�޶� ������ 
gap �̻��� �Ǵ� ����� �ִ����� ��ȯ�Ѵ�. 
(����ȭ ������ ������ ���� ���� ������ ��ȯ�Ͽ� �ذ��ϴ� ���� �ذ� ���)

+ ī�޶� ��ġ�� �� �ִ� ��������, ��� ��ġ�ϴ� Ž���� ��� ���! 

*/
bool decision(const vector <double> & location, int cameras, double gap) {
	double limit = -1;
	int installed = 0;
	for (int i = 0; i < location.size(), ++i) {
		if (limit <= location[i]) {
			++installed;
			limit = location[i] + gap;
			// location[i] + gap ���Ĵ� �Ǿ�� ī�޶� ��ġ�� �����ϴ�. 
		}
	}
	return installed >= cameras;
	// ��������� cameras �� �̻� ��ġ�ߴٸ� ����! 
}




/*

2nd : ����ȭ ����
���ĵǾ� �ִ� locations �� cameras�� ������ �ּ� ������ �ִ�ȭ�Ѵ�.
1st �׳� ����ȭ ������ �ִ� �Ͱ��� ������ ���� �����̴�! :)

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