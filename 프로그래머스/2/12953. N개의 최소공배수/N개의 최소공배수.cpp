#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int hoje(int a, int b) {
    
    while(true) {        
        if (a%b == 0) {
            return b;
        }
        else {
            int tmp = a;
            a = b;
            b = tmp % b;
        }
    }
}

int solution(vector<int> arr) {
    int answer = 1;
    
    for (int i = 0; i < arr.size(); i++) {
        int gcd = hoje(arr[i], answer);
        answer *= arr[i]/gcd;
    }
    return answer;
}