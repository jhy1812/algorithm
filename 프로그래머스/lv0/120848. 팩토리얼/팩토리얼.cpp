#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 1;
    int gob = 1;
    while (true){
        gob *= answer;
        if (gob > n){
            break;
        }
        answer += 1;
    }
    return answer - 1;
}