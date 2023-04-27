#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int answer = -1;
    int l = int(num_list.size());
    for (int i = 0; i<l; i++){
        if (num_list[i] < 0){
            answer = i;
            break;
        }
    }
    return answer;
}