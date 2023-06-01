#include <iostream>
#include <string>

int N;

int main()
{
    std::cin >> N;
    
    for(int i=0;i<N;i++){
std::string tmp;
        std::cin>>tmp;
        if(6<=int(tmp.size()) && int(tmp.size())<=9){
std::cout << "yes" << "\n";
}
        else{
std::cout << "no" << "\n";
}
}

    return 0;
}