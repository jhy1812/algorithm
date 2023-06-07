#include <iostream>
#include <algorithm>

int main()
{
    int a, b, c;
    
    std::cin >> a >> b >> c;
    
    if (a >= b && a >= c){
        while (true){
            if (a < b+c){
                break;
            }
            a -= 1;
        }
    }
    else if (b >= a && b >= c){
        while (true){
            if (b < a + c){
                break;
            }
            b -= 1;
        }
    }
    else if (c >= a && c >= b){
        while (true){
            if (c < a + b){
                break;
            }
            c -= 1;
        }
    }
    
    std::cout << a + b + c;
    
    return 0;
}