#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    int mod = 1;
    
    while(true) {
        if (n%mod == 1) {
            answer = mod;
            break;
        }
        mod++;
    }
    
    return answer;
}