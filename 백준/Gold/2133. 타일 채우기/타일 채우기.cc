#include <iostream>
#include <algorithm>

int N;
long long result;
long long dp[31];

void dfs(int len, int num) {
	if (len > N) {
		return;
	}
	if (len == N) {
		result += num;
		return;
	}
	for (int i = 2; i <= N; i += 2) {
		dfs(len + i, num * dp[i]);
	}
}

int main()
{
	std::cin >> N;

	dp[2] = 3;

	for (int i = 4; i <= 30; i += 2) {
		dp[i] = 2;
	}

	if (N % 2 == 1 || N == 0) {
		std::cout << 0;
	}
	else {
		dfs(0, 1);
		std::cout << result;
	}

	return 0;
}