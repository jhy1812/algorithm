#include <iostream>
#include <string>
using namespace std;

int main()
{
	string N;
	int leng, maxx;
	maxx = 0;
	int bucket[10] = { 0, };
	cin >> N;
	leng = N.length();
	for (int i = 0; i < leng; i++) {
		bucket[N[i] - '0'] += 1;
	}
	for (int i = 0; i < 9; i++) {
		if (i == 6) {
			if ((bucket[i] + bucket[9]) % 2 == 0) {
				if (maxx < (bucket[i] + bucket[9]) / 2) {
					maxx = (bucket[i] + bucket[9]) / 2;
				}
			}
			else {
				if (maxx < (bucket[i] + bucket[9]) / 2 +1) {
					maxx = (bucket[i] + bucket[9]) / 2 + 1;
				}
			}
		}
		else {
			if (maxx < bucket[i]) {
				maxx = bucket[i];
			}
		}
	}
	cout << maxx;
}