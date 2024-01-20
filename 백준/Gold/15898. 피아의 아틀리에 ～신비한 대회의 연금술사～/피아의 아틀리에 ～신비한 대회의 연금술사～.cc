#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

std::pair<int, int> stp[4] = { std::make_pair(0, 0), std::make_pair(0, 1), std::make_pair(1, 0), std::make_pair(1, 1) };

int n, result;
std::map<char, int> qsc;
std::vector<int> visited(10, 0);
std::vector<int> material(3, 0);
std::vector<int> stspot(3, 0);
std::vector<int> rotation(3, 0);
std::vector<std::vector<std::vector<std::vector<int>>>> mq;			// 재료 품질
std::vector<std::vector<std::vector<std::vector<char>>>> mc;		// 재료 색
std::vector<std::vector<std::pair<int, char>>> kk(5, std::vector<std::pair<int, char>>(5, std::make_pair(0, 'W')));

std::vector<std::vector<int>> rq(int num, std::vector<std::vector<int>> bf) {
	if (num == 0) {
		return bf;
	}

	std::vector<std::vector<int>> af(4, std::vector<int>(4, 0));

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (num == 1) {
				af[j][4 - i - 1] = bf[i][j];
			}
			else if (num == 2) {
				af[4 - i - 1][4 - j - 1] = bf[i][j];
			}
			else {
				af[4 - j - 1][i] = bf[i][j];
			}
		}
	}
	
	return af;
}

std::vector<std::vector<char>> rc(int num, std::vector<std::vector<char>> bf) {
	if (num == 0) {
		return bf;
	}

	std::vector<std::vector<char>> af(4, std::vector<char>(4, 'W'));

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (num == 1) {
				af[j][4 - i - 1] = bf[i][j];
			}
			else if (num == 2) {
				af[4 - i - 1][4 - j - 1] = bf[i][j];
			}
			else {
				af[4 - j - 1][i] = bf[i][j];
			}
		}
	}

	return af;
} 

void get_result() {
	std::vector<std::vector<std::pair<int, char>>> tmpk(5, std::vector<std::pair<int, char>>(5, std::make_pair(0, 'W')));

	for (int i = 0; i < 3; i++) { //재료, 회전, 시작
		for (int j = 0; j < 5; j++) { // 좌표
			for (int k = 0; k < 5; k++) { // 좌표
				if (0 <= j - stp[stspot[i]].first && j - stp[stspot[i]].first < 4 && 0 <= k - stp[stspot[i]].second && k - stp[stspot[i]].second < 4) {
					tmpk[j][k].first = mq[material[i]][rotation[i]][j - stp[stspot[i]].first][k - stp[stspot[i]].second] + tmpk[j][k].first;
					if (mc[material[i]][rotation[i]][j - stp[stspot[i]].first][k - stp[stspot[i]].second] == 'W') {
						tmpk[j][k].second = tmpk[j][k].second;
					}
					else {
						tmpk[j][k].second = mc[material[i]][rotation[i]][j - stp[stspot[i]].first][k - stp[stspot[i]].second];
					}
				}
				else {
					tmpk[j][k].first = tmpk[j][k].first;
					tmpk[j][k].second = tmpk[j][k].second;
				}
				if (tmpk[j][k].first < 0) {
					tmpk[j][k].first = 0;
				}
				else if (tmpk[j][k].first > 9) {
					tmpk[j][k].first = 9;
				}
			}
		}

		if (i == 2) {
			int tresult = 0;

			for (int j = 0; j < 5; j++) {
				for (int k = 0; k < 5; k++) {
					tresult += qsc[tmpk[j][k].second] * tmpk[j][k].first;
				}
			}

			result = std::max(tresult, result);
		}
	}
}

void dfs(int lv) {
	if (lv == 3) {
		get_result();

		return;
	}

	for (int i = 0; i < n; i++) {
		if (visited[i] == 0) {
			visited[i] = 1;
		}
		else {
			continue;
		}
		material[lv] = i;
		for (int j = 0; j < 4; j++) {
			rotation[lv] = j;
			for (int k = 0; k < 4; k++) {
				stspot[lv] = k;
				dfs(lv + 1);
			}
		}
		visited[i] = 0;
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	qsc['W'] = 0;
	qsc['Y'] = 2;
	qsc['G'] = 3;
	qsc['B'] = 5;
	qsc['R'] = 7;

	std::cin >> n;

	mq.resize(n);
	mc.resize(n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++) {
			mq[i].push_back({});
			mc[i].push_back({});
		}
		for (int j = 0; j < 4; j++) {
			mq[i][0].push_back({});
			for (int k = 0; k < 4; k++) {
				int tmp;
				std::cin >> tmp;
				mq[i][0][j].push_back(tmp);
			}
		}
		for (int j = 0; j < 4; j++) {
			mc[i][0].push_back({});
			for (int k = 0; k < 4; k++) {
				char tmp;
				std::cin >> tmp;
				mc[i][0][j].push_back(tmp);
			}
		}

		for (int j = 1; j < 4; j++) {
			std::vector<std::vector<int>> tmp;
			tmp = rq(j, mq[i][0]);
			mq[i][j] = tmp;

			std::vector<std::vector<char>> tmpp;
			tmpp = rc(j, mc[i][0]);
			mc[i][j] = tmpp;
		}
	}

	dfs(0);

	std::cout << result;


	return 0;
}