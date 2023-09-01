#include <iostream>

long long n;
long long t[36];

int main(void) {
	std::cin >> n;
    
	t[0] = 1;
	t[1] = 1;
	
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			t[i] += (t[j] * t[i - 1 - j]);
		}
	}
    
	std::cout << t[n];
	
    return 0;
}