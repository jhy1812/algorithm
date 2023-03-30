#include <iostream>
#include <algorithm>

using namespace std;

long long N, minn1, minn2, minn3; 
long long dice[6];
long long result;

long long maju(long long a) {
	if (a == 0) {
		return 5;
	}
	else if (a == 1) {
		return 4;
	}
	else if (a == 2) {
		return 3;
	}
	else if (a == 3) {
		return 2;
	}
	else if (a == 4) {
		return 1;
	}
	else {
		return 0;
	}
}

long long two(long long arr[]) {
	long long minn = 1e10;
	for (int i = 0; i < 6; i++) {
		long long summ = 0;
		for (int j = 0; j < 6; j++) {
			if (i == j || maju(i) == j) {
				continue;
			}
			else {
				summ = arr[i] + arr[j];
				if (minn > summ) {
					minn = summ;
				}
			}

		}
	}
	return minn;
}

long long three(long long arr[]) {
	long long minn = 1e10;
	minn = min(arr[0] + arr[1] + arr[2], arr[0] + arr[1] + arr[3]);
	minn = min(minn, arr[0] + arr[3] + arr[4]);
	minn = min(minn, arr[0] + arr[2] + arr[4]);
	minn = min(minn, arr[5] + arr[1] + arr[2]);
	minn = min(minn, arr[5] + arr[1] + arr[3]);
	minn = min(minn, arr[5] + arr[3] + arr[4]);
	minn = min(minn, arr[5] + arr[2] + arr[4]);
	return minn;
}


int main()
{
	cin >> N;
	minn1 = 1e8;
	for (int i = 0; i < 6; i++) {
		cin >> dice[i];
		if (minn1 > dice[i]) {
			minn1 = dice[i];
		}
	}

	if (N == 1) {
		int maxx = 0;
		int summ = 0;
		for (int i = 0; i < 6; i++) {
			if (maxx < dice[i]) {
				maxx = dice[i];
			}
			summ += dice[i];
		}
		cout << summ - maxx;
	}
	else {
		minn2 = two(dice);
		minn3 = three(dice);
		result = minn1 * ((N - 2)*(N - 1)*4 + (N-2)*(N-2)) + minn2 * ((N - 1) * 4 + (N - 2) * 4) + minn3 * 4;
		cout << result;
	}
	return 0;
}