#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    int mod = 1;
    int check = 0;
    int check2 = 0;
    
    while (true) {
        if ((n/mod)%2 == 1) {
            check++;
        }
        else if (mod > n) {
            break;
        }
        mod *= 2;        
    }
    
    while (check != check2) {
        n++;
        check2 = 0;
        mod = 1;
        while (true) {
            if ((n/mod)%2 == 1) {
                check2++;
            }
            else if (mod > n) {
                break;
            }
            mod *= 2;
        }
    }
    
     
    return n;
}