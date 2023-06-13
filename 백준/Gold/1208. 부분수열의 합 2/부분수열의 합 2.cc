#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

int N, S;
long long result;
std::vector<int>arr(1);
std::map<int, int>hap;

void left_sum(int lv, int summ) {
	if (lv == N / 2 + 1) {
		hap[summ]++;
		return;
	}

	left_sum(lv + 1, summ + arr[lv]);
	left_sum(lv + 1, summ);
}

void right_sum(int lv, int summ) {
	if (lv == N + 1) {
		result += hap[S - summ];
		return;
	}

	right_sum(lv + 1, summ + arr[lv]);
	right_sum(lv + 1, summ);
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N >> S;

	for (int i = 0; i < N; i++) {
		int tmp;
		std::cin >> tmp;
		arr.push_back(tmp);
	}

	left_sum(1, 0);
	right_sum(N / 2 + 1, 0);

	if (S == 0) {
		result -= 1;
	}

	std::cout << result;

	return 0;
}