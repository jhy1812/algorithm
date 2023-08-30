#include <iostream>

int m;
int arr[4] = { 0, 1, 2, 3 };

int main() {
    std::cin >> m;
	
	for (int i = 0; i < m; i++) {
		int fir, sec;
		std::cin >> fir >> sec;
		std::swap(arr[fir], arr[sec]);
	}

	int i = 1;
    
	while (true) {
		if (arr[i] == 1) {
			std::cout << i << '\n';
			break;
		}
		i++;
	}
	
	return 0;
}