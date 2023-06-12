#include <iostream>

int N, K, result;

int main()
{
    std::cin >> N >> K;
    
    result = 1;
    
    for (int i = N; i > K; i--){
        result *= i;
    }
    
    for (int i = 1; i <= N-K; i++){
        result = result/i;
    }
    
    std::cout << result;
    
    return 0;
}