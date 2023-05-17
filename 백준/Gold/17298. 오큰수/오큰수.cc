#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
#include <vector>

int N;
std::vector<int>result(1000001, -1);
std::stack<std::pair<int, int>>sutack;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;

	for (int i = 0; i < N; i++) {
		int tmp;
		std::cin >> tmp;
		if (int(sutack.size()) == 0) {
			sutack.push(std::make_pair(tmp, i));
		}
		else if (sutack.top().first < tmp) {
			while (true) {
				if (int(sutack.size()) == 0) {
					sutack.push(std::make_pair(tmp, i));
					break;
				}
				else if (sutack.top().first >= tmp) {
					sutack.push(std::make_pair(tmp, i));
					break;
				}
				result[sutack.top().second] = tmp;
				sutack.pop();
			}
		}
		else {
			sutack.push(std::make_pair(tmp, i));
		}
	}

	for (int i = 0; i < N; i++) {
		std::cout << result[i] << " ";
	}

	return 0;
}