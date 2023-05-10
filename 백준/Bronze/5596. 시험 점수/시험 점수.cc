#include <iostream>
#include <algorithm>

int main()
{
    int minguk, mansae;
    minguk = 0;
    mansae = 0;
    for (int i =0;i<4; i++){
        int tmp;
        std::cin >> tmp;
        minguk += tmp;
    }
    
    for(int i =0;i<4;i++){
        int tmp;
        std::cin >> tmp;
        mansae += tmp;
    }
    
    std::cout << std::max(minguk, mansae);
    
    return 0;
}