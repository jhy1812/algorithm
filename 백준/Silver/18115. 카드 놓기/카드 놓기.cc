#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

int N;
std::vector<int> arr;
std::stack<int> back;
std::vector<int> front;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;

	for (int i = 0; i < N; i++) {
		int tmp;
		std::cin >> tmp;
		arr.push_back(tmp);
	}

	for (int i = arr.size() - 1; i >= 0; i--) {
		if (arr[i] == 1) {
			back.push(N - i);
		}
		else if (arr[i] == 2) {
			int tmp = back.top();
			back.pop();
			back.push(N - i);
			back.push(tmp);
		}
		else {
			front.push_back(N - i);
		}
	}

	while (!back.empty()) {
		std::cout << back.top() << " ";
		back.pop();
	}

	for (int i = 0; i < front.size(); i++) {
		std::cout << front[i] << " ";
	}

	return 0;
}