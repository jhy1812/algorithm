#include <iostream>
#include <vector>
#include <algorithm>

int N, maxx;
std::vector<std::pair<int, int>>schedule;

void dfs(int lv, int summ) {
	if (lv >= N) {
		maxx = std::max(maxx, summ);
		return;
	}
	if (lv + schedule[lv].first > N) {
		maxx = std::max(maxx, summ);
		dfs(lv + 1, summ);
		return;
	}
	dfs(lv + schedule[lv].first, summ + schedule[lv].second);
	dfs(lv + 1, summ);
}

int main()
{
	std::cin >> N;

	for (int i = 0; i < N; i++) {
		int t, p;
		std::cin >> t >> p;
		schedule.push_back(std::make_pair(t, p));
	}

	dfs(0, 0);

	std::cout << maxx;

	return 0;
}