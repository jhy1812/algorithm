#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    for (int i = 0; i<int(numbers.size()); i++){
        for (int j = i+1; j < int(numbers.size()); j++){
            if (numbers[i]*numbers[j] > answer){
                answer = numbers[i]*numbers[j];
            }
        }
    }
    return answer;
}