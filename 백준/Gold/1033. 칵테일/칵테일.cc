#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

long long N, a, b, p, q;
vector<long long>arr(10, -1);
vector<long long>result(10, 1);

int findboss(long long a) {
	if (arr[a] == -1) {
		return a;
	}
	long long ret = findboss(arr[a]);
	arr[a] = ret;
	return ret;
}

void setunion(long long a, long long b) {
	long long fa = findboss(a);
	long long fb = findboss(b);
	if (fa == fb) {
		return;
	}
	arr[fb] = fa;
}

long long hoje(long long a, long long b) {
	while (true) {
		if (a%b == 0) {
			return b;
		}
		else {
			int tmp = a;
			a = b;
			b = tmp % b;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b >> p >> q;
		long long tmp = hoje(p, q);
		p = p / tmp;
		q = q / tmp;
		long long aboss = findboss(a);
		long long bboss = findboss(b);
		p *= (result[b] / (hoje(result[a], result[b])));
		q *= (result[a] / (hoje(result[a], result[b])));
		long long agcd = hoje(p, q);
		long long bgcd = hoje(p, q);
		p = p / agcd;
		q = q / bgcd;
		for (int i = 0; i < N; i++) {
			if (findboss(i) == aboss) {
				result[i] *= p;
			}
			if (findboss(i) == bboss) {
				result[i] *= q;
			}
		}
		setunion(a, b);
	}

	for (int i = 0; i < N; i++) {
		cout << result[i] << " ";
	}

	return 0;
}