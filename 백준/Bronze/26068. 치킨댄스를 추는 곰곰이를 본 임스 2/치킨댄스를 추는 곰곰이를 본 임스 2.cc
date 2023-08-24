#include <iostream>
#include <string>

int main() {
  int n; 
  std::cin >> n;

  int result = 0;
  for (int i = 0; i < n; i++) {
    std::string g; 
    std::cin >> g;
    int d = stoi(g.substr(2));
    if (d <= 90) {
      result++;  
    }
  }

  std::cout << result << "\n";

  return 0;
}