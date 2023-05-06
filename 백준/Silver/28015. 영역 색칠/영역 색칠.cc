#include <iostream>
#include <stack>
#include <algorithm>

int N, M, check, flag, cnt, result;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N >> M;

	for (int i = 0; i < N; i++) {
		flag = 0;
		check = 0;
		result += cnt;
		cnt = 0;
		for (int j = 0; j < M; j++) {
			int tmp;
			std::cin >> tmp;
			if (flag == 0 && tmp != 0 && check == 0) {
				check = tmp;
				cnt += 1;
				flag = 1;
			}
			else if (tmp == 0) {
				flag = 0;
				result += cnt;
				cnt = 0;
				check = 0;
			}
			else if (flag == 1 && check != tmp) {
				cnt += 1;
				flag = 0;
			}
			else if (check == tmp) {
				flag = 1;
			}

		}
	}


	result += cnt;

	std::cout << result;

	return 0;
}