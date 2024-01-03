#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

int n, num, idx, flag;
std::vector<int> arr;
std::vector<char> result;
std::stack<int> st;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> n;

	arr.push_back(0);

	for (int i = 0; i < n; i++) {
		int tmp;
		std::cin >> tmp;
		arr.push_back(tmp);
	}

	num = 1;
	idx = 1;

	while (num <= n + 1 && idx <= n + 1) {
		if (idx > n) {
			break;
		}
		if (arr[idx] >= num) {
			st.push(num++);
			result.push_back('+');
		}
		else if (arr[idx] < num) {
			if (st.top() == arr[idx]) {
				st.pop();
				result.push_back('-');
				idx++;
			}
			else {
				flag = 1;
				break;
			}
		}
	}

	if (flag) {
		std::cout << "NO";
	}
	else {
		for (int i = 0; i < result.size(); i++) {
			std::cout << result[i] << "\n";
		}
	}

	return 0;
}