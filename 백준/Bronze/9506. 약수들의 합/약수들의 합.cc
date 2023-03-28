#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n, cnt, summ;
	while (true) {
		cin >> n;
		cnt = 0;
		summ = 0;
		if (n == -1) {
			break;
		}
		for (int i = 1; i < n; i++) {
			if (n % i == 0) {
				summ += i;
			}
		}
		if (n == summ) {
			cout << n << " = " << 1 << " ";
			for (int i = 2; i < n; i++) {
				if (n % i == 0) {
					cout << "+ " << i << " ";
				}
			}
		}
		else {
			cout << n << " is NOT perfect.";
		}
		cout << "\n";
	}
}