#include <iostream>
#include <algorithm>

int main(){
    int li1[4], li2[2], sum = 0;
    for(int i=0; i<4; i++){
        std::cin>>li1[i];
    }
    for(int i=0; i<2; i++){
        std::cin>>li2[i];
    }
    
    std::sort(li1, li1+4);
    std::sort(li2, li2+2);
    
    for(int i=1; i<4; i++){
        sum += li1[i];
    }
    sum += std::max(li2[0], li2[1]);
    
    std::cout<<sum;
    return 0;
}