#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

int N, M, result;
std::map<std::string, int>arr;
std::vector<std::string>lst;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N >> M;

	for (int i = 0; i < N; i++) {
		std::string s;
		std::cin >> s;
		arr[s]++;
	}

	for (int i = 0; i < M; i++) {
		std::string s;
		std::cin >> s;
		result += arr[s];
		if (arr[s] == 1) {
			lst.push_back(s);
		}
	}


	sort(lst.begin(), lst.end());

	std::cout << result << "\n";

	for (int i = 0; i<int(lst.size()); i++) {
		std::cout << lst[i] << "\n";
	}

	return 0;
}