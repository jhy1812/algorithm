#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int answer = 0;
    int n = int(num_list.size());
    if (n > 10){
        for (int i=0; i < n; i++){
            answer += num_list[i];
        }
    }
    else {
        answer = 1;
        for (int i = 0; i<n; i++){
            answer *= num_list[i];
        }
    }
    return answer;
}