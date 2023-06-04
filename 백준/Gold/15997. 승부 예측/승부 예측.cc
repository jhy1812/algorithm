#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

struct game
{
	string t1;
	string t2;
	double win1;
	double draw;
	double win2;
};

int n = 4;

map<string, double>result;
map<string, int>score;
map<int, string>tnum;
vector<game>games;


void simul_game(int lv, double perc) {
	if (perc == 0.0) {
		return;
	}
	if (lv == n + 2) {
		vector<pair<int, int>>check;
		for (int i = 0; i < n; i++) {
			check.push_back(make_pair(score[tnum[i]], i));
		}
		sort(check.begin(), check.end());
		int g1 = 1;
		int g2 = 0;

		vector<int>gs1;
		vector<int>gs2;
		gs1.push_back(check[3].second);
		for (int i = 2; i >= 0; i--) {
			if (check[i].first == check[3].first) {
				g1 += 1;
				gs1.push_back(check[i].second);
			}
			else {
				break;
			}

		}
		if (g1 < 2) {
			g2 = 1;
			gs2.push_back(check[n - g1 - 1].second);
			for (int i = n - g1 - 2; i >= 0; i--) {
				if (check[i].first == check[n - g1 - 1].first) {
					g2 += 1;
					gs2.push_back(check[i].second);
				}
				else {
					break;
				}
			}
		}
		if (g1 <= 2) {
			for (int i = 0; i < g1; i++) {
				result[tnum[gs1[i]]] = result[tnum[gs1[i]]] + perc;
			}
		}
		else {
			for (int i = 0; i < g1; i++) {
				result[tnum[gs1[i]]] = result[tnum[gs1[i]]] + (double)(2 * perc / g1);
			}
		}
		for (int i = 0; i < g2; i++) {
			result[tnum[gs2[i]]] = result[tnum[gs2[i]]] + (double)(perc / g2);
		}
		return;
	}
	for (int i = 0; i < 3; i++) {
		if (i == 0) {
			score[games[lv].t1] += 3;
			simul_game(lv + 1, perc * games[lv].win1);
			score[games[lv].t1] -= 3;
		}
		else if (i == 1) {
			score[games[lv].t1] += 1;
			score[games[lv].t2] += 1;
			simul_game(lv + 1, perc * games[lv].draw);
			score[games[lv].t1] -= 1;
			score[games[lv].t2] -= 1;
		}
		else {
			score[games[lv].t2] += 3;
			simul_game(lv + 1, perc * games[lv].win2);
			score[games[lv].t2] -= 3;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		score.insert(pair<string, int>(tmp, 0));
		tnum.insert(pair<int, string>(i, tmp));
	}

	for (int i = 0; i < n + 2; i++) {
		game tmp;
		string team1, team2;
		double a, b, c;
		cin >> team1 >> team2 >> a >> b >> c;
		tmp.t1 = team1;
		tmp.t2 = team2;
		tmp.win1 = a;
		tmp.draw = b;
		tmp.win2 = c;
		games.push_back(tmp);
	}

	simul_game(0, 1.0);

	for (int i = 0; i < n; i++) {
		cout << fixed;
		cout.precision(10);
		cout << result[tnum[i]] << "\n";
	}

	return 0;
}