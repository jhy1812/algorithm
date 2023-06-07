#include <iostream>
#include <cmath>

int n, w, h;

int main()
{
    std::cin >> n >> w >> h;
    
    for (int i = 0; i< n; i++){
        int tmp;
        std::cin >> tmp;
        if (w*w + h*h >= tmp*tmp){
            std::cout << "DA" << "\n";
        }
        else {
            std::cout << "NE" << "\n";
        }
    }    
    
    return 0;
}