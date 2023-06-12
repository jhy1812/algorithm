#include <iostream>
#include <queue>
#include <string>

int N, a;
std::string order = "";
std::queue<int>q;

int main()
{
	std::cin >> N;

	for (int i = 0; i < N; i++) {
		std::cin >> order;
		if (order == "push") {
			std::cin >> a;
			q.push(a);
		}
		else if (order == "pop") {
			if (int(q.size()) == 0) {
				std::cout << -1 << "\n";
			}
			else {
				int tmp = q.front();
				std::cout << tmp << "\n";
				q.pop();
			}
		}
		else if (order == "size") {
			std::cout << int(q.size()) << "\n";
		}
		else if (order == "empty") {
			if (int(q.size()) == 0) {
				std::cout << 1 << "\n";
			}
			else {
				std::cout << 0 << "\n";
			}
		}
		else if (order == "front") {
			if (int(q.size()) == 0) {
				std::cout << -1 << "\n";
			}
			else {
				std::cout << q.front() << "\n";
			}
		}
		else if (order == "back") {
			if (int(q.size()) == 0) {
				std::cout << -1 << "\n";
			}
			else {
				std::cout << q.back() << "\n";
			}
		}
	}

	return 0;
}