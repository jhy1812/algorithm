#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

int N;
std::priority_queue<int, std::vector<int>, std::greater<int>> q;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;

	for (int i = 0; i < N; i++) {
		int tmp;
		std::cin >> tmp;
		if (tmp == 0) {
			if (q.size() == 0) {
				std::cout << 0 << "\n";
			}
			else {
				std::cout << q.top() << "\n";
				q.pop();
			}
		}
		else {
			q.push(tmp);
		}
	}

	return 0;
}