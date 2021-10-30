#include <iostream>
#include <vector>

using namespace std;

int findingMajorNumber(const vector<int> &Vec) {
	int N = Vec.size();
	int majority = -1;
	int majorityCount = 0;

	for (int i = 0; i < N; ++i) {
		int array = Vec[i];
		int count = 0;
		for (int j = 0; j < N; ++j) {
			if (Vec[j] == array) {
				++count;
			}
		}

		if (count > majorityCount) {
			majorityCount = count;
			majority = array;
		}
	}
	return majority;sss
}

int findingMajorNumber2(const vector<int>& Vec) {
	int N = Vec.size();
	vector<int> count(101, 0);

	for (int i = 0; i < N; ++i) {
		count[Vec[i]]++;
	}

	int majority = 0;
	for (int i = 0; i < 100; ++i) {
		if (count[i] > count[majority]) {
			majority = i;
		}
	}
	return majority;
}


int main() {

}