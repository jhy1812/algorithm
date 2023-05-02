#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, flag;
long long money, balance, beM, afM;
vector<long long> check_list;

long long hoje(long long a, long long b) {
	while (true) {
		if (a%b == 0) {
			return b;
		}
		long long tmp = a;
		a = b;
		b = tmp % b;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		long long tmp;
		cin >> money >> tmp;
		if (money >= 0) {
			if (balance + money != tmp) {
				flag = 1;
				break;
			}
			balance = tmp;
		}
		else {
			if (balance + money >= 0) {
				if (balance + money != tmp) {
					flag = 1;
					break;
				}
				balance = tmp;
			}
			else {
				afM = tmp - money - balance;
				if (beM == 0) {
					beM = afM;
					check_list.push_back(tmp);
				}
				else {
					beM = hoje(beM, afM);
					check_list.push_back(tmp);
				}
			}
			balance = tmp;
		}
	}

	for (int i = 0; i<int(check_list.size()); i++) {
		if (check_list[i] - beM >= 0) {
			flag = 1;
		}
	}

	if (beM == 0) {
		beM = 1;
	}

	if (flag == 1) {
		cout << -1;
	}
	else {
		cout << beM;
	}

	return 0;
}