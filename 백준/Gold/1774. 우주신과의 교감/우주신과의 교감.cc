#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

struct info {
	int a;
	int b;
	double dis;
};

bool cmp(info a, info b) {
	return a.dis < b.dis;
}

int N, M, exi, cnt;
double result;
std::vector<std::pair<long, long>> spot(1);
std::vector<int> arr(1001, -1);
std::vector<info> path;

int findboss(int a) {
	if (arr[a] == -1) {
		return a;
	}
	int ret = findboss(arr[a]);
	arr[a] = ret;
	return ret;
}

bool uni(int a, int b) {
	int fa = findboss(a);
	int fb = findboss(b);
	
	if (fa == fb) {
		return false;
	}
	arr[fb] = fa;
	return true;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N >> M;

	for (int i = 0; i < N; i++) {
		long long xx, yy;
		std::cin >> xx >> yy;
		spot.push_back(std::make_pair(xx, yy));
	}

	for (int i = 0; i < M; i++) {
		int a, b;
		std::cin >> a >> b;
		if (a > b) {
			int tmp = a;
			a = b;
			b = tmp;
		}
		if (findboss(a) != findboss(b)) {
			uni(a, b);
			exi++;
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			info tmp;
			tmp.a = i;
			tmp.b = j;
			tmp.dis = sqrt((spot[i].first - spot[j].first) * (spot[i].first - spot[j].first) + (spot[i].second - spot[j].second) * (spot[i].second - spot[j].second));
			path.push_back(tmp);
		}
	}

	std::sort(path.begin(), path.end(), cmp);

	for (int i = 0; i < path.size(); i++) {
		if (uni(path[i].a, path[i].b)) {
			cnt++;
			result += path[i].dis;
		}
		if (N - 1 == cnt + exi) {
			break;
		}
	}

	result = std::round(result * 100) / 100.0;

	std::cout << std::fixed;
	std::cout.precision(2);
	std::cout << result;

	return 0;
}