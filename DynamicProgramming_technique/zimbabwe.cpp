#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// 웨바브짐 계란 가격을 찾아보자!



/* 웨바브짐 문제의 답을 모두 찾는 완전 탐색 알고리즘


이전 계란 가격은 다음 세가지 조건을 만족해야 한다. 

1. 새 계란 각격 e에 포함된 숫자들을 재배열한 결과
2. 새 계란 가격 e보다 작아야 한다.
3. m으로 나누어 떨어져야 한다. 




[사용할 문제 해결 방법]

e의 각 자릿수를 정렬해서 digits에 저장한 다음
이번에 사용할 자릿수 바로 앞 자리가,

1. 없거나 (i = 0)
2. 이번 자릿수랑 다르거나 (digits[i - 1] != digits[i])
3. 이미 사용됨 (taken[i - 1] = true)

위와 같은 경우에만 사용할 수 있도록 한다. 





- digits : e의 자릿수들을 정렬한 배열
- price : 지금까지 만든 가격
- taken : 각 자릿수의 사용 여부 (boolean)

+ e를 string으로 선언한 이유
: 자릿수 단위로 숫자를 다루는 경우, 문자열이 훨씬 간편하다.

*/




string e;
string digits;
int n;
int m;

void generate(string price, bool taken[15]) {
	if (price.size() == n) {
		if (price < e) { 
			cout << price << endl;
			// 둘 다 문자열이지만, 자릿수가 같기에 price와 e를 비교할 수 있다. wow
		}
		return;
		// 기저사례 : 계란의 가격을 찾았다!
	}

	for (int i = 0; i < n; ++i) {
		if (taken[i] == false 
			&& (i == 0 || digits[i - 1] != digits[i] || taken[i - 1] = true)) 
		{
			taken[i] = true;
			generate(price + digits[i], taken);
			taken[i] = false;
		}
	}
}






/* 웨바브짐 문제를 해결하는 동적 계획법 알고리즘 


- 자릿수를 위해 문자열을 사용했으나, 이로 인하여 메모이제이션이 까다로워졌다. 
- boolean 값인 taken은 비트마스크를 통하여 정수로 변환 가능하다. 
- but, 문자열 price를 메모이제이션 하는 것은 까다롭다. 
: 같은 price를 두 번 만들 일은 없기 때문에 price를 그대로 메모이제이션에 사용하면
중복되는 부분 문제가 하나도 없음.


- 따라서 우리는 해당 작업을 하는 최소한의 정보만 재귀 호출에 전달!
: 그래야 중복 문제가 많이 생겨서, 메모이제이션을 최대한 활용할 수 있으니까. 

[지금까지 만든 가격인 price가 사용되는 부분]

1. n 자리를 모두 구성했는지 판단할 때
2. 다 만든 가격이 사탕 가격의 배수인지 판단할 때
3. 다 만든 가격이 나중 가격보다 작은지 확인할 때 


1번은 taken의 모든 원소가 true인지 판별하는 것으로 대체 가능 : okay


2번 -> 가격이 오른 것이 맞는가?

: 우리가 손으로 나눗셈을 하는 과정을 살펴보면, 
ex) 7284 대신 13284가 7로 나누어 떨어지는 지 확인하는 과정
나머지가 같다면 앞에 어떤 수가 왔는지는 중요하지 않다. 

즉, price를 전달하는 대신, price를 m으로 나눈 나머지를 전달하자. 
: 마지막에 price가 m으로 나누어 떨어지는 지 판별하는 데는 지장X
: m으로 나눈 나머지는 0부터 m-1까지! 따라서 메모이제이션 가능!


3번 -> 사탕 가격의 배수가 맞는가? 

계란의 새 가격 e가 231 이라고 가정해보자. 
이때 첫 자리에 들어갈 수 있는 수는 총 3개
1: 앞으로 어떻게 배치하든 이 수는 231보다 작음
2: 앞으로 어떻게 배치하느냐에 따라 이 수는 231보다 크거나 작음
3: 앞으로 어떻게 배치하든 이 수는 231보다 큼
: 따라서 1 OR 2 의 경우만 가능하다. (이전의 계란 가격은 더 저렴해야 하니까)

따라서 우리는 재귀 호출에 
- price는 이미 e보다 작으니 나머지는 아무렇게나 해라(1의 경우) OR
- price는 e보다 커질 수 있으니 주의해라 (2의 경우)
라는 정보만 전달하면 된다. 

이후 모든 자리를 구성했을 때, price가 e보다 작은지 아닌지를 
boolean 값 less로 표현한다. 
- less = true : 앞부분보다 작으므로, 항상 e보다 작은 상태
= less = false : price와 e의 앞부분이 일치한다. 




- price : 지금까지 만든 가격 
- index : 이번에 채울 자리의 인덱스
- taken : 지금까지 사용한 자릿수들의 집합
- mod : price의 m에 대한 나머지
- less : price가 이미 e보다 작으면 1, 아니면 0 (boolean)


*/


const int MOD = 1000000007;
string e;
string digits;
int n;
int m;
int cache[1 << 14][20][2];

int price(int index, int taken, int mod, int less) {
	if (index == n) {
		if (less == true && mod == 0) {
			return 1;
		}
		else {
			return 0;
		}
	}

	// 메모이제이션
	int& ret = cache[taken][mod][less];
	if (ret != -1) {
		return ret;
	}

	ret = 0;
	for (int next = 0; next < n; ++next) {
		if ((taken == true & (1 << next)) == 0) {
			if (less == false && (e[index] < digits[next])) {
				// 과거 가격은 항상 새로운 가격보다 작아야 함.
				continue;
			}
			if (next > 0 && digits[next - 1] == digits[next] && (taken & (1 << (next - 1))) == 0) {
				// 같은 숫자는 한 번만 선택
				continue;
			}
			int nextTaken = taken | (1 << next);
			int nextMod = (mod * 10 + digits[next] - '0') % m;
			int nextLess = less || e[index] > digits[next];
			ret += price(index + 1, nextTaken, nextMod, nextLess);
			ret %= MOD;
		}
	}
	return ret;
}




/*


	[비트 연산자 정리]

<< X : X만큼 왼쪽으로 비트들 이동
>> X : X만큼 오른쪽으로 비트들 이동
~ : 비트들을 반전시킨다. (다 반대로, 보수)
& (AND) : 대응되는 비트가 모두 1일 때 1이다.
| (OR) : 대응되는 비트가 모두 0일 때 0이다.
^ (XOR) : 두 비트가 달라야 1이다. (둘이 같으면 0)


*/
