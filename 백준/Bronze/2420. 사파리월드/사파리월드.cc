#include <iostream>

using namespace std;

long long N, M;

int main() {
	cin >> N >> M;
	long long result = 0;
	result = N - M;
	if (result < 0) {
		result = -result;
	}
	cout << result;
	return 0;
}