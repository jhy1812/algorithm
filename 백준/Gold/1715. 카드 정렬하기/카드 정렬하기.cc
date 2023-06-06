#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

int N;
long long result;
std::priority_queue<int, std::vector<int>, std::greater<int>>cards;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;

	for (int i = 0; i < N; i++) {
		int tmp;
		std::cin >> tmp;
		cards.push(tmp);
	}

	if (N == 1) {
		std::cout << 0;
	}
	else {
		int card1 = cards.top();
		cards.pop();
		int card2 = cards.top();
		cards.pop();
		result += card1 + card2;
		int now = card1 + card2;
		for (int i = 0; i < N - 2; i++) {
			if (cards.size() == 1) {
				result += now + cards.top();
				break;
			}
			card1 = cards.top();
			cards.pop();
			card2 = cards.top();
			if (card2 < now) {
				cards.push(now);
				cards.pop();
				now = card1 + card2;
				result += now;
			}
			else {
				now += card1;
				result += now;
			}
		}
		std::cout << result;
	}

	return 0;
}