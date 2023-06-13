#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

#define MAXX 500000

int N, K;
std::vector<std::vector<int>>visited(500001, std::vector<int>(2, -1));

void bfs(int st) {
	std::queue<int>q;
	q.push(st);
	visited[st][0] = 0;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < 3; i++) {
			int nex;
			int check = 0;
			if (i == 0) {
				nex = now - 1;
			}
			else if (i == 1) {
				nex = now + 1;
			}
			else {
				nex = 2 * now;
			}
			if (0 <= nex && nex <= MAXX) {
				if (visited[now][0] != -1) {
					if (visited[nex][1] == -1) {
						visited[nex][1] = visited[now][0] + 1;
						q.push(nex);
						check = 1;
					}
				}
				if (visited[now][1] != -1) {
					if (visited[nex][0] == -1) {
						visited[nex][0] = visited[now][1] + 1;
						if (check == 0) {
							q.push(nex);
						}
					}
				}
			}
		}
	}
}

int main()
{
	std::cin >> N >> K;

	if (N == K) {
		std::cout << 0;
	}
	else {
		bfs(N);
		int cnt = 0;
		int flag = 0;
		int result = 0;
		while (true) {
			if (K + (cnt * (cnt + 1)) / 2 > MAXX) {
				break;
			}
			if (visited[K + (cnt * (cnt + 1)) / 2][cnt % 2] <= cnt) {
				flag = 1;
				result = cnt;
				break;
			}
			cnt += 1;
		}
		if (flag == 1) {
			std::cout << result;
		}
		else {
			std::cout << -1;
		}
	}

	return 0;
}