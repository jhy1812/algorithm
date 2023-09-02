#include <iostream>
#include <string>
#include <algorithm>

int result = 51;
std::string A, B;

int main()
{
	std::cin >> A >> B;

	for (int i = 0; i <= B.size() - A.size(); i++) {
		int cnt = 0;
		for (int j = 0; j < A.size(); j++) {
			if (A[j] != B[i + j]) {
				cnt++;
			}
		}
		result = std::min(result, cnt);
	}

	std::cout << result;

	return 0;
}