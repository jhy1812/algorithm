#include <iostream>
#include <stack>
#include <algorithm>

int K;
long long result;
std::stack<int>arr;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> K;

	for (int i = 0; i < K; i++) {
		int tmp;
		std::cin >> tmp;
		if (tmp == 0) {
			arr.pop();
		}
		else {
			arr.push(tmp);
		}
	}

	int leng = int(arr.size());

	for (int i = 0; i<leng; i++) {
		result += arr.top();
		arr.pop();
	}

	std::cout << result;

	return 0;
}