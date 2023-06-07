#include <iostream>
#include <algorithm>
#include <cmath>

int r, w, l, cnt;

int main()
{
    while(true){
        cnt += 1;
        std::cin >> r;
        if (r == 0){
            break;
        }
        std::cin >> w >> l;
        if (4*r*r >= w*w + l*l){
            std::cout << "Pizza " << cnt << " fits on the table." << "\n";
        }
        else {
            std::cout << "Pizza " << cnt << " does not fit on the table." << "\n";
        }
    }
    
    return 0;
}