#include <iostream>
#include <cmath>

using namespace std;

long long int A, B, n, m;
long long int cnta, cntb;
int flag;

int main()
{
	cin >> A >> B;
	for (int i = 57; i > 0; i--) {
		if (B >= (long long)(pow(2, i)) && flag == 0) {
			m = i;
			flag = 1;
		}
		if (A - 1 >= (long long)(pow(2, i))) {
			n = i;
			break;
		}
	}

	for (int i = 1; i <= m + 1; i++) {
		if (i == 1) {
			cntb += ((B + 1) / (long long)(pow(2, i))) * (long long)(pow(2, i - 1));

		}
		else {
			cntb += ((B + 1) / (long long)(pow(2, i))) * (long long)(pow(2, i - 1)) + (((B + 1) / (long long)(pow(2, i - 1))) % 2) * ((B + 1) % (long long)(pow(2, i - 1)));
		}
	}
	for (int i = 1; i <= n + 1; i++) {
		if (i == 1) {
			cnta += ((A) / (long long)(pow(2, i))) * (long long)(pow(2, i - 1));
		}
		else {
			cnta += ((A) / (long long)(pow(2, i))) * (long long)(pow(2, i - 1)) + (((A) / (long long)(pow(2, i - 1))) % 2) * ((A) % (long long)(pow(2, i - 1)));
		}
	}
	cout << cntb - cnta;
	return 0;
}