#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::vector<int> v(3);
    
    for (int i = 0; i < 3; i++) {
        int tmp;
        std::cin >> tmp;
        v[i] = tmp;
    }

    std::sort(v.begin(), v.end());
    
    std::cout << v[1] << "\n";

  return 0;
}