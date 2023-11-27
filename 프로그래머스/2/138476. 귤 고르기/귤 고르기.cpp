#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int solution(int k, vector<int> tangerine) {
    map<int, int> tsize;
    vector<int> check;
    int answer = 0;
    for (int i = 0; i < tangerine.size(); i++) {
        tsize[tangerine[i]]++;
        if (tsize[tangerine[i]] == 1) {
            check.push_back(tangerine[i]);
        }
    }
    
    for (int i = 0; i < check.size(); i++) {
        check[i] = tsize[check[i]];
    }
    
    sort(check.begin(), check.end(), greater<>());
    
    int summ = 0;
    
    for (int i = 0; i < check.size(); i++) {
        summ += check[i];
        if (summ >= k) {
            answer = i + 1;
            break;
        }
    }
    
    return answer;
}