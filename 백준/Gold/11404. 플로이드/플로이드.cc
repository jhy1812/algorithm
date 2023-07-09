#include <iostream>
#include <algorithm>
#include <vector>

#define INF 100000009

int n, m;
std::vector<std::vector<int>> arr(100, std::vector<int>(100, INF));

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> n;
	std::cin >> m;

	for (int i = 0; i < m; i++) {
		int a, b, c;
		std::cin >> a >> b >> c;
		if (c < arr[a - 1][b - 1]) {
			arr[a - 1][b - 1] = c;
		}
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				arr[i][j] = std::min(arr[i][j], arr[i][k] + arr[k][j]);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == INF || i == j) {
				std::cout << 0 << " ";
			}
			else {
				std::cout << arr[i][j] << " ";
			}
		}
		std::cout << "\n";
	}

	return 0;
}