#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <queue>
using namespace std;



// 문자열의 길이가 주어질 때, 하나로 합치는 최소 비용을 구한다. 

int concat(const vector<int>& lengths) {
	priority_queue<int, vector<int>, greater<int> > pq;
	for (int i = 0; i < lengths.size(); ++i) {
		pq.push(lengths[i]);
	}	
	int ret = 0;
	while (pq.size() > 1) {
		int min1 = pq.top();
		pq.pop();
		int min2 = pq.top();
		pq.pop();

		pq.push(min1 + min2);
		ret += (min1 + min2);
	}
	return ret;
}
