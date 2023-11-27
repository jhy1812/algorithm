#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    
    answer.push_back(0);
    answer.push_back(0);
    
    while (true) {
        int c = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                c++;
            }    
        }
        if (c == 1 && s.size() == 1) {
            break;
        }
        answer[0]++;
        answer[1] += s.size() - c;
        s = "";
        while (c > 0) {
            if (c%2 == 0) {
                s = "0" + s;
            }
            else {
                s = "1" + s;
            }
            c /=  2;
        }
    }
    
    return answer;
}