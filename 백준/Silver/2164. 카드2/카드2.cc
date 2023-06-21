#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>

int N;
std::queue<int>arr;

int main()
{
	std::cin >> N;

	for (int i = 1; i <= N; i++) {
		arr.push(i);
	}

	while (true) {
		if (int(arr.size()) == 1) {
			break;
		}
		arr.pop();
		int tmp = arr.front();
		arr.pop();
		arr.push(tmp);
	}

	std::cout << arr.front();

	return 0;
}