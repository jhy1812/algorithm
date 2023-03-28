#include <iostream>
#include <string>
using namespace std;

int main()
{
	int N, i;
	cin >> N;
	i = 2;
	while (N > 1) {
		if (N % i == 0) {
			N = N / i;
			if (N != 1) {
				cout << i << "\n";
			}
			else {
				cout << i;
			}
			while (N % i == 0) {
				N = N / i;
				if (N != 1) {
					cout << i << "\n";
				}
				else {
					cout << i;
				}
			}
		}
		else {
			i += 1;
		}
	}
	return 0;
}