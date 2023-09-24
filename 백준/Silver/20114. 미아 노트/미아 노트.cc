#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int N, H, W;
std::string result;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N >> H >> W;

	for (int i = 0; i < N; i++) {
		result += '?';
	}

	for (int i = 0; i < H; i++) {
		std::string tmp;
		std::cin >> tmp;
		for (int j = 0; j < N * W; j++) {
			if (tmp[j] != '?') {
				result[j / W] = tmp[j];
			}
		}
	}

	std::cout << result;

	return 0;
}