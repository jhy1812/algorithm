#include <iostream>
#include <algorithm>

int T;
int a, b, c;

int main()
{
    std::cin >> T;
    
    for (int tc = 1; tc<=T; tc++){
        std::cin >> a >> b >> c;
        std::cout << "Scenario #" << tc << ":" << "\n";
        int maxx = std::max(a, std::max(b, c));
        if (maxx == a){
            if (a*a == b*b + c*c){
                std::cout << "yes" << "\n";
            }
            else {
                std::cout << "no" << "\n";
            }
        }
        else if (maxx == b){
            if (b*b == a*a + c*c){
                std::cout << "yes" << "\n";
            }
            else {
                std::cout << "no" << "\n";
            }
        }
        else if (maxx == c){
            if (c*c == a*a + b*b){
                std::cout << "yes" << "\n";
            }
            else {
                std::cout << "no" << "\n";
            }
        }
        std::cout << "\n";
    }
    
    return 0;
}