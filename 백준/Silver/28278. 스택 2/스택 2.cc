#include <iostream>
#include <algorithm>
#include <stack>

int N;
std::stack<int> st;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;

	for (int i = 0; i < N; i++) {
		int order;
		std::cin >> order;
		if (order == 1) {
			int num;
			std::cin >> num;
			st.push(num);
		}
		else if (order == 2) {
			if (st.empty()) {
				std::cout << -1 << "\n";
			}
			else {
				std::cout << st.top() << "\n";
				st.pop();
			}
		}
		else if (order == 3) {
			std::cout << st.size() << "\n";
		}
		else if (order == 4) {
			if (st.empty()) {
				std::cout << 1 << "\n";
			}
			else {
				std::cout << 0 << "\n";
			}
		}
		else {
			if (st.empty()) {
				std::cout << -1 << "\n";
			}
			else {
				std::cout << st.top() << "\n";
			}
		}
	}

	return 0;
}