#include <iostream>
#include <algorithm>
#include <map>
#include <string>

int N, M;
std::map<std::string, std::string> site;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N >> M;

	for (int i = 0; i < N; i++) {
		std::string a, b;
		std::cin >> a >> b;

		site[a] = b;
	}

	for (int i = 0; i < M; i++) {
		std::string a;
		std::cin >> a;
		std::cout << site[a] << "\n";
	}

	return 0;
}