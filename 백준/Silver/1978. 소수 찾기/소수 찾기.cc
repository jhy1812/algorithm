#include <iostream>
#include <string>
using namespace std;

int main()
{
	int N, cnt, a, result;
	cin >> N;
	result = 0;
	for (int i = 0; i < N; i++) {
		cnt = 0;
		cin >> a;
		for (int j = 1; j <= (a / 2); j++) {
			if (a % j == 0) {
				cnt += 1;
			}
			if (cnt > 1) {
				break;
			}
		}
		if (cnt <= 1 && a != 1) {
			result += 1;
		}
	}
	cout << result;

}