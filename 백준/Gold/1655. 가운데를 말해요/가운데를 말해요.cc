#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

int N, result;
std::priority_queue<int> q1;
std::priority_queue<int, std::vector<int>, std::greater<int>> q2;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;

	int tmp;
	std::cin >> tmp;
	result = tmp;
	q1.push(result);

	std::cout << result << "\n";

	for (int i = 2; i <= N; i++) {
		std::cin >> tmp;
		if (i % 2 == 0) {
			if (result <= tmp) {
				q2.push(tmp);
				std::cout << result << "\n";
			}
			else {
				q2.push(result);
				q1.pop();
				q1.push(tmp);
				result = q1.top();
				std::cout << result << "\n";
			}
		}
		else {
			if (result < tmp) {
				q2.push(tmp);
				result = q2.top();
				q2.pop();
				q1.push(result);
				std::cout << result << "\n";
			}
			else {
				q1.push(tmp);
				std::cout << result << "\n";
			}
		}
	}

	return 0;
}