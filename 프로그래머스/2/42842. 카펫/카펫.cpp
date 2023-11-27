#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int area = brown + yellow;
    int mod = 1;
    
    while (mod <= sqrt(area)) {
        if (area%mod == 0) {
            if ((mod - 2)*(area/mod - 2) == yellow) {
                answer.push_back(area/mod);
                answer.push_back(mod);
                break;
            }
        }
        mod++;
    }
    
    return answer;
}