#include <string>
#include <vector>

using namespace std;

int solution(string n_str) {
    int answer = 0;
    int cnt = 1;
    for (int i = int(n_str.length())-1; i>=0; i--){
        answer += cnt*(n_str[i]-'0');
        cnt *= 10;
    }
    return answer;
}