#include <iostream>
#include <string>
using namespace std;

int main()
{
	int N, K, cnt, result;
	cin >> N >> K;
	cnt = 0;
	result = 0;
	for (int i = 1; i <= N; i++) {
		if (N % i == 0) {
			cnt += 1;
		}
		if (cnt == K) {
			result = i;
			break;
		}
	}
	if (cnt == K) {
		cout << result;
	}
	else {
		cout << 0;
	}
}