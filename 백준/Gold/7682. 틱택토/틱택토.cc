#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int xcnt, ocnt;
std::string board;

bool check(char target) {
	if (board[0] == target && board[1] == target && board[2] == target) {
		return true;
	}
	if (board[0] == target && board[4] == target && board[8] == target) {
		return true;
	}
	if (board[0] == target && board[3] == target && board[6] == target) {
		return true;
	}
	if (board[1] == target && board[4] == target && board[7] == target) {
		return true;
	}
	if (board[2] == target && board[5] == target && board[8] == target) {
		return true;
	}
	if (board[2] == target && board[4] == target && board[6] == target) {
		return true;
	}
	if (board[3] == target && board[4] == target && board[5] == target) {
		return true;
	}
	if (board[6] == target && board[7] == target && board[8] == target) {
		return true;
	}
	return false;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	while (true) {
		std::cin >> board;
		if (board == "end") {
			break;
		}
		xcnt = 0;
		ocnt = 0;

		for (int i = 0; i < 9; i++) {
			if (board[i] == 'X') {
				xcnt++;
			}
			else if (board[i] == 'O') {
				ocnt++;
			}
		}

		if (xcnt == ocnt) {
			if (check('O')) {
				if (check('X')) {
					std::cout << "invalid" << "\n";
				}
				else {
					std::cout << "valid" << "\n";
				}
			}
			else {
				std::cout << "invalid" << "\n";
			}
		}
		else if (xcnt == ocnt + 1) {
			if (xcnt + ocnt == 9) {
				if (check('O')) {
					std::cout << "invalid" << "\n";
				}
				else {
					std::cout << "valid" << "\n";
				}
			}
			else {
				if (check('O')) {
					std::cout << "invalid" << "\n";
				}
				else if (check('X')) {
					std::cout << "valid" << "\n";
				}
				else {
					std::cout << "invalid" << "\n";
				}
			}
		}
		else {
			std::cout << "invalid" << "\n";
		}
	}

	return 0;
}