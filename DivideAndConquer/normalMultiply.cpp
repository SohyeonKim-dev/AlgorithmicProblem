#include <iostream>
#include <vector>
using namespace std;

// num[]�� �ڸ��� �ø��� ó���Ѵ�. 
void normalize(vector <int>& num) {
	num.push_back(0);

	for (int i = 0; i + 1 < num.size(); ++i) {
		if (num[i] < 0) {
			int borrow = (abs(num[i]) + 9) / 10;
			num[i + 1] -= borrow;
			num[i] += borrow * 10;
		}
		else {
			num[i + 1] += num[i] / 10;
			num[i] %= 10;
		}
	}
	while (num.size() > 1 && num.back() == 0) {
		num.pop_back();
	}
}

// �Ųٷ� ����� ���� ��Һ� ���� ����Ѵ�. 
//ex) multiply({3,2,1},{6,5,4}) = 123 * 456 = 50688 = {8,8,0,6,5} 

vector <int> multiply(const vector<int>& a, const vector<int>& b) {
	vector<int> c (a.size() + b.size() + 1, 0); // 0���� �ʱ�ȭ
	for (int i = 0; i < a.size(); ++i) {
		for (int j = 0; j < b.size(); ++j) {
			c[i + j] += a[i] * b[j];
		}
	}
	normalize(c); // �ڸ��� �ø� ó�� ���� ��ȯ 
	return c;
}

int main() {
	vector <int> firstNum = { 3, 2, 1};
	vector <int> secondNum = { 6, 5, 4 };
	vector <int> ret = multiply(firstNum, secondNum);
	for (int i = 0; i < ret.size(); ++i) {
		cout << ret[i] << endl;
	}
}

/*

[Output]

8
8
0
6
5

*/