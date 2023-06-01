#include <iostream>
#include <vector>
#include <algorithm>

int N, M;
long long result;
std::vector<long long>arr(1);
std::vector<long long>modarr;

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

	for (int i = 0; i < M; i++) {
		modarr.push_back(0);
	}

	for (int i = 1; i <= N; i++) {
		arr[i] = arr[i] + arr[i - 1];  
	}

	for (int i = 1; i <= N; i++) {
		arr[i] = arr[i] % M;
	}

	for (int i = 0; i <= N; i++) {
		modarr[arr[i]] += 1;
	}

	for (int i = 0; i < M; i++) {
		if (modarr[i] >= 2) {
			result += (modarr[i] * (modarr[i] - 1)) / 2;
		}
	}

	std::cout << result;

	return 0;
}