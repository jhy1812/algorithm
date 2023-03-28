#include <iostream>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	float N, summ, a, maxx;
	float arr[1000] = { 0, };
	float avg;
	summ = 0;
	maxx = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		if (maxx < arr[i]) {
			maxx = arr[i];
		}
	}
	for (int i = 0; i < N; i++) {
		arr[i] = arr[i] / maxx * 100;
		summ += arr[i];
	}

	avg = summ / N;
	cout << fixed;
	cout << avg;
	return 0;
}