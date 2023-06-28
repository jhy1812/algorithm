#include <iostream>
#include <string>
#include <vector>

int T, n;

void rot(char& b1, char& b2, char& b3, char& b4) {
	char tmp;
	tmp = b1;
	b1 = b2;
	b2 = b3;
	b3 = b4;
	b4 = tmp;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::vector<std::vector<char>> upp(3, std::vector<char>(3));
	std::vector<std::vector<char>> bot(3, std::vector<char>(3));
	std::vector<std::vector<char>> fro(3, std::vector<char>(3));
	std::vector<std::vector<char>> bac(3, std::vector<char>(3));
	std::vector<std::vector<char>> lef(3, std::vector<char>(3));
	std::vector<std::vector<char>> rig(3, std::vector<char>(3));

	std::cin >> T;

	for (int tc = 0; tc < T; tc++) {
		std::cin >> n;

		upp = { {'w','w','w'},{'w','w','w'},{'w','w','w'} };
		bot = { {'y','y','y'},{'y','y','y'},{'y','y','y'} };
		fro = { {'r','r','r'},{'r','r','r'},{'r','r','r'} };
		bac = { {'o','o','o'},{'o','o','o'},{'o','o','o'} };
		lef = { {'g','g','g'},{'g','g','g'},{'g','g','g'} };
		rig = { {'b','b','b'},{'b','b','b'},{'b','b','b'} };

		for (int i = 0; i < n; i++) {
			std::string tmp;
			std::cin >> tmp;
			if (tmp[0] == 'U') {
				if (tmp[1] == '+') {
					rot(upp[0][0], upp[2][0], upp[2][2], upp[0][2]);
					rot(upp[0][1], upp[1][0], upp[2][1], upp[1][2]);
					rot(rig[0][0], bac[0][0], lef[0][0], fro[0][0]);
					rot(rig[0][1], bac[0][1], lef[0][1], fro[0][1]);
					rot(rig[0][2], bac[0][2], lef[0][2], fro[0][2]);
				}
				else {
					rot(upp[0][0], upp[0][2], upp[2][2], upp[2][0]);
					rot(upp[0][1], upp[1][2], upp[2][1], upp[1][0]);
					rot(rig[0][1], fro[0][1], lef[0][1], bac[0][1]);
					rot(rig[0][0], fro[0][0], lef[0][0], bac[0][0]);
					rot(rig[0][2], fro[0][2], lef[0][2], bac[0][2]);
				}
			}
			else if (tmp[0] == 'D') {
				if (tmp[1] == '+') {
					rot(bot[0][0], bot[2][0], bot[2][2], bot[0][2]);
					rot(bot[0][1], bot[1][0], bot[2][1], bot[1][2]);
					rot(rig[2][0], fro[2][0], lef[2][0], bac[2][0]);
					rot(rig[2][1], fro[2][1], lef[2][1], bac[2][1]);
					rot(rig[2][2], fro[2][2], lef[2][2], bac[2][2]);
				}
				else {
					rot(bot[0][0], bot[0][2], bot[2][2], bot[2][0]);
					rot(bot[0][1], bot[1][2], bot[2][1], bot[1][0]);
					rot(rig[2][0], bac[2][0], lef[2][0], fro[2][0]);
					rot(rig[2][1], bac[2][1], lef[2][1], fro[2][1]);
					rot(rig[2][2], bac[2][2], lef[2][2], fro[2][2]);
				}
			}
			else if (tmp[0] == 'F') {
				if (tmp[1] == '+') {
					rot(fro[0][0], fro[2][0], fro[2][2], fro[0][2]);
					rot(fro[0][1], fro[1][0], fro[2][1], fro[1][2]);
					rot(rig[0][0], upp[2][0], lef[2][2], bot[0][2]);
					rot(rig[1][0], upp[2][1], lef[1][2], bot[0][1]);
					rot(rig[2][0], upp[2][2], lef[0][2], bot[0][0]);
				}
				else {
					rot(fro[0][0], fro[0][2], fro[2][2], fro[2][0]);
					rot(fro[0][1], fro[1][2], fro[2][1], fro[1][0]);
					rot(rig[0][0], bot[0][2], lef[2][2], upp[2][0]);
					rot(rig[1][0], bot[0][1], lef[1][2], upp[2][1]);
					rot(rig[2][0], bot[0][0], lef[0][2], upp[2][2]);
				}
			}
			else if (tmp[0] == 'B') {
				if (tmp[1] == '+') {
					rot(bac[0][0], bac[2][0], bac[2][2], bac[0][2]);
					rot(bac[0][1], bac[1][0], bac[2][1], bac[1][2]);
					rot(rig[0][2], bot[2][2], lef[2][0], upp[0][0]);
					rot(rig[1][2], bot[2][1], lef[1][0], upp[0][1]);
					rot(rig[2][2], bot[2][0], lef[0][0], upp[0][2]);
				}
				else {
					rot(bac[0][0], bac[0][2], bac[2][2], bac[2][0]);
					rot(bac[0][1], bac[1][2], bac[2][1], bac[1][0]);
					rot(rig[0][2], upp[0][0], lef[2][0], bot[2][2]);
					rot(rig[1][2], upp[0][1], lef[1][0], bot[2][1]);
					rot(rig[2][2], upp[0][2], lef[0][0], bot[2][0]);
				}
			}
			else if (tmp[0] == 'L') {
				if (tmp[1] == '+') {
					rot(lef[0][0], lef[2][0], lef[2][2], lef[0][2]);
					rot(lef[0][1], lef[1][0], lef[2][1], lef[1][2]);
					rot(upp[2][0], bac[0][2], bot[2][0], fro[2][0]);
					rot(upp[1][0], bac[1][2], bot[1][0], fro[1][0]);
					rot(upp[0][0], bac[2][2], bot[0][0], fro[0][0]);
				}
				else {
					rot(lef[0][0], lef[0][2], lef[2][2], lef[2][0]);
					rot(lef[0][1], lef[1][2], lef[2][1], lef[1][0]);
					rot(upp[2][0], fro[2][0], bot[2][0], bac[0][2]);
					rot(upp[1][0], fro[1][0], bot[1][0], bac[1][2]);
					rot(upp[0][0], fro[0][0], bot[0][0], bac[2][2]);
				}
			}
			else if (tmp[0] == 'R') {
				if (tmp[1] == '+') {
					rot(rig[0][0], rig[2][0], rig[2][2], rig[0][2]);
					rot(rig[0][1], rig[1][0], rig[2][1], rig[1][2]);
					rot(bot[0][2], bac[2][0], upp[0][2], fro[0][2]);
					rot(bot[1][2], bac[1][0], upp[1][2], fro[1][2]);
					rot(bot[2][2], bac[0][0], upp[2][2], fro[2][2]);
				}
				else {
					rot(rig[0][0], rig[0][2], rig[2][2], rig[2][0]);
					rot(rig[0][1], rig[1][2], rig[2][1], rig[1][0]);
					rot(bot[0][2], fro[0][2], upp[0][2], bac[2][0]);
					rot(bot[1][2], fro[1][2], upp[1][2], bac[1][0]);
					rot(bot[2][2], fro[2][2], upp[2][2], bac[0][0]);
				}
			}
		}
		
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				std::cout << upp[i][j];
			}
			std::cout << "\n";
		}
	}

	return 0;
}