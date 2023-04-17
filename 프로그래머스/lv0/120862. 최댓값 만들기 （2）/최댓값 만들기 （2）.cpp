#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> numbers) {
    sort(numbers.begin(), numbers.end());
    
    int a = numbers[0]*numbers[1];
    int b = numbers[int(numbers.size()) -1]*numbers[int(numbers.size()) -2];
    
    
    int answer = 0;
    answer = max(a, b);
    return answer;
}