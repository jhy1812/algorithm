#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> sides) {
    sort(sides.begin(), sides.end(), greater<int>());
    int answer = 0;
    if (sides[0] < sides[1] + sides[2]){
        answer = 1;    
    }
    else{
        answer = 2;
    }
    
    return answer;
}