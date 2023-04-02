#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int N, st, ed, result, summ, cnt;
int arr[4000001];
vector<int> prime;

int main()
{
	cin >> N;
	if (N == 1) {
		cout << 0;
	}
	else {
		for (int i = 2; i <= int(sqrt(N)) + 1; i++) {
			for (int j = 2 * i; j <= N; j += i) {
				arr[j] = 1;
			}
		}
		for (int i = 2; i <= N; i++) {
			if (arr[i] == 0) {
				prime.push_back(i);
				cnt += 1;
			}
		}

		summ = prime[0];
		ed = 1;
		while (true) {
			if (st >= cnt && ed >= cnt) {
				break;
			}
			if (summ == N) {
				result += 1;
				summ -= prime[st];
				st += 1;
			}
			else if (summ > N) {
				summ -= prime[st];
				st += 1;
			}
			else if (summ < N) {
				if (ed >= cnt) {
					break;
				}
				summ += prime[ed];
				ed += 1;
			}
		}
		cout << result;
	}
	return 0;
}