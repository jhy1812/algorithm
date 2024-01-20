#include <iostream>
#include <algorithm>
#include <map>

long long A, B, cnt, result;
std::map<long long, long long> num;

int main()
{
	std::cin >> A >> B;

	cnt = 1;

	for (int i = 0; i < 62; i++) {
		num[cnt] = 0;
	
		num[cnt] += ((B + 1) / (cnt * 2)) * cnt;

		if ((B + 1) % (cnt * 2) != 0 && B >= cnt) {
			if ((B + 1) % (cnt * 2) - cnt >= 0) {
				num[cnt] += (B + 1) % (cnt * 2) - cnt;
			}
		}

		

		num[cnt] -= (A / (cnt * 2)) * cnt;

		if (A % (cnt * 2) != 0 && A - 1 >= cnt) {
			if (A % (cnt * 2) - cnt >= 0) {
				num[cnt] -= A % (cnt * 2) - cnt;
			}
		}

		if (num[cnt] % 2 == 1) {
			result += cnt;
		}

		cnt *= 2;
	}

	std::cout << result;

	return 0;
}