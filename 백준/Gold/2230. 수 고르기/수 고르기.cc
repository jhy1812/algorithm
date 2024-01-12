#include <iostream>
#include <algorithm>
#include <vector>

long long N, M, st, ed, result;
std::vector<long long> arr;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N >> M;

	for (int i = 0; i < N; i++) {
		long long tmp;
		std::cin >> tmp;
		arr.push_back(tmp);
	}

	std::sort(arr.begin(), arr.end());
	result = 2000000001;
	ed = 1;

	while (true) {
		if (st >= N - 1 && ed >= N - 1) {
			break;
		}
		else if (ed >= N - 1) {
			st++;
		}
		else if (st == ed) {
			ed++;
		}
		else if (arr[ed] - arr[st] < M) {
			ed++;
		}
		else if (arr[ed] - arr[st] >= M) {
			result = std::min(arr[ed] - arr[st], result);
			st++;
		}
		if (arr[ed] - arr[st] >= M) {
			result = std::min(arr[ed] - arr[st], result);
		}
	}

	std::cout << result;

	return 0;
}