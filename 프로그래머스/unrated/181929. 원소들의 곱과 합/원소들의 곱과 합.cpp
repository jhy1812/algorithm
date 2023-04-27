#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int answer = 0;
    int summ = 0;
    int gob = 1;
    int l = int(num_list.size());
    for (int i = 0; i<l; i++){
        summ += num_list[i];
        gob *= num_list[i];
    }
    if (gob < summ*summ){
        answer = 1;
    }
    return answer;
}