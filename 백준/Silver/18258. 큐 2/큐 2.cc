#include <iostream>
#include <queue>
#include <string>

int N;
std::queue<int> q;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;

	for (int i = 0; i < N; i++) {
		std::string order;
		std::cin >> order;
		if (order == "push") {
			int num;
			std::cin >> num;
			q.push(num);
		}
		else if (order == "pop") {
			if (q.size() == 0) {
				std::cout << -1 << "\n";
			}
			else {
				int num;
				num = q.front();
				q.pop();
				std::cout << num << "\n";
			}
		}
		else if (order == "size") {
			std::cout << q.size() << "\n";
		}
		else if (order == "empty") {
			if (q.empty()) {
				std::cout << 1 << "\n";
			}
			else {
				std::cout << 0 << "\n";
			}
		}
		else if (order == "front") {
			if (q.size() == 0) {
				std::cout << -1 << "\n";
			}
			else {
				int num;
				num = q.front();
				std::cout << num << "\n";
			}
		}
		else if (order == "back") {
			if (q.size() == 0) {
				std::cout << -1 << "\n";
			}
			else {
				int num;
				num = q.back();
				std::cout << num << "\n";
			}
		}
	}

	return 0;
}