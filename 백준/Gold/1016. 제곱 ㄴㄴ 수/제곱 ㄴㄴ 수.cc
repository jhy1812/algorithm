#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int result, cnt;
long long minn, maxx;
vector<int>arr(1001002);
vector<int>check(1001002);
vector<long long>prime;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> minn >> maxx;

	for (int i = 2; i<int(sqrt(maxx)) + 1; i++) {
		if (arr[i] == 1) {
			continue;
		}
		prime.push_back((long long)pow(i, 2));
		for (int j = 2 * i; j<int(sqrt(maxx)) + 1; j += i) {
			arr[j] = 1;
		}
	}

	for (int i = 0; i<int(prime.size()); i++) {
		long long mok = minn / prime[i];
		for (long long j = mok*prime[i]; j <= maxx; j += prime[i]) {
			if (j < minn) {
				continue;
			}
			if (check[j-minn] == 1) {
				continue;
			}
			cnt += 1;
			check[j-minn] = 1;
		}
	}

	cout << maxx - minn - cnt + 1;

	return 0;
}