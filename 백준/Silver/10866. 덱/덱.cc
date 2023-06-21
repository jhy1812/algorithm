#include <iostream>
#include <algorithm>
#include <deque>
#include <string>

int N;
std::deque<int>arr;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;

	for (int i = 0; i < N; i++) {
		std::string order;
		std::cin >> order;
		if (order == "push_front") {
			int tmp;
			std::cin >> tmp;
			arr.push_front(tmp);
		}
		else if (order == "push_back") {
			int tmp;
			std::cin >> tmp;
			arr.push_back(tmp);
		}
		else if (order == "pop_front") {
			if (int(arr.size()) == 0) {
				std::cout << -1 << "\n";
			}
			else {
				int tmp = arr.front();
				arr.pop_front();
				std::cout << tmp << "\n";
			}
		}
		else if (order == "pop_back") {
			if (int(arr.size()) == 0) {
				std::cout << -1 << "\n";
			}
			else {
				int tmp = arr.back();
				arr.pop_back();
				std::cout << tmp << "\n";
			}
		}
		else if (order == "size") {
			std::cout << int(arr.size()) << "\n";
		}
		else if (order == "empty") {
			if (arr.empty()) {
				std::cout << 1 << "\n";
			}
			else {
				std::cout << 0 << "\n";
			}
		}
		else if (order == "front") {
			if (arr.empty()) {
				std::cout << -1 << "\n";
			}
			else {
				std::cout << arr.front() << "\n";
			}
		}
		else if (order == "back") {
			if (arr.empty()) {
				std::cout << -1 << "\n";
			}
			else {
				std::cout << arr.back() << "\n";
			}
		}
	}

	return 0;
}