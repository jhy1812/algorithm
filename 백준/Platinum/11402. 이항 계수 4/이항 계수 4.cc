#include <iostream>
#include <algorithm>
#include <cmath>

long long N, K, M;

int main()
{
	std::cin >> N >> K >> M;

	long long su = N;
	long long mocount = 0;
	long long jacount = 0;

	long long mull = 1;
	for (int i = 1; i < M; i++) {
		mull = (mull * i) % M;
	}

	while (true) {
		if (su / M == 0) {
			break;
		}
		mocount += su / M;
		su = su / M;
	}

	su = K;
	while (true) {
		if (su / M == 0) {
			break;
		}
		jacount += su / M;
		su = su / M;
	}

	su = N - K;
	while (true) {
		if (su / M == 0) {
			break;
		}
		jacount += su / M;
		su = su / M;
	}

	if (mocount > jacount) {
		std::cout << 0;
	}
	else {
		long long result = 1;
		long long tmp = N;
		while (true) {
			if (tmp / M == 0) {
				for (int i = 1; i <= tmp; i++) {
					result = (result * i) % M;
				}
				break;
			}
			long long ttmp = tmp / M;
			long long mmull = mull;
			for (int i = 1; i <= tmp % M; i++) {
				result = (result * i) % M;
			}
			while (ttmp > 0) {
				if (ttmp % 2 == 1) {
					result = (result * mmull) % M;
				}
				ttmp = ttmp / 2;
				mmull = (mmull * mmull) % M;
			}
			tmp = tmp / M;
		}

		long long divv = 1;
		tmp = K;
		while (true) {
			if (tmp / M == 0) {
				for (int i = 1; i <= tmp; i++) {
					divv = (divv * i) % M;
				}
				break;
			}
			long long ttmp = tmp / M;
			long long mmull = mull;
			for (int i = 1; i <= tmp % M; i++) {
				divv = (divv * i) % M;
			}
			while (ttmp > 0) {
				if (ttmp % 2 == 1) {
					divv = (divv * mmull) % M;
				}
				ttmp = ttmp / 2;
				mmull = (mmull * mmull) % M;
			}
			tmp = tmp / M;
		}

		tmp = N - K;
		while (true) {
			if (tmp / M == 0) {
				for (int i = 1; i <= tmp; i++) {
					divv = (divv * i) % M;
				}
				break;
			}
			long long ttmp = tmp / M;
			long long mmull = mull;
			for (int i = 1; i <= tmp % M; i++) {
				divv = (divv * i) % M;
			}
			while (ttmp > 0) {
				if (ttmp % 2 == 1) {
					divv = (divv * mmull) % M;
				}
				ttmp = ttmp / 2;
				mmull = (mmull * mmull) % M;
			}
			tmp = tmp / M;
		}
		

		int p = M - 2;
		while (p > 0) {
			if (p % 2 == 1) {
				result = (result * divv) % M;
			}
			p = p / 2;
			divv = (divv * divv) % M;
		}
		std::cout << result;
	}

	return 0;
}