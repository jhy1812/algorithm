#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    int mod = 1;
    
    while(mod*mod <= n) {
        if (mod*mod == n) {
            answer += mod;
        }
        else if (n%mod == 0) {
            answer += mod;
            answer += n/mod;
        }
        mod++;
    }
    
    return answer;
}