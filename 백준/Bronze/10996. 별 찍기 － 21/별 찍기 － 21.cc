#include <iostream>

int n;

int main(){
    std::cin >> n;

    if (n == 1) {
        std::cout << "*";
    }
	else {
        for(int i = 1; i <= n * 2; i++){
            for(int j = 1; j <= n; j ++){
                if(i % 2 == 1){
                    if(j % 2 == 1) {
                        std::cout << "*";                    
                    }
                    else {
                        std::cout << " ";                    
                    }
                }
                else{
                    if (j % 2 == 1) {
                        std::cout << " ";                    
                    } 
                    else {
                        std::cout << "*";
                    }
                }
            }
            std::cout << "\n";
        }
    }
    

    return 0;
}