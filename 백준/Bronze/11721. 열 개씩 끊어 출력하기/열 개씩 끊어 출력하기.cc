#include <iostream>
#include <string>

std::string s;

int main()
{
    std::cin >> s;
    
    for(int i=0; i<int(s.size()); i++){
        std::cout << s[i];
        if (i%10 == 9){
            std::cout << "\n";
        }
    }
    
    return 0;
}