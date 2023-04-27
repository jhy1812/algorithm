#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int n) {
    string answer = "";
    int l = int(my_string.size());
    for (int i = l-n; i<l; i++){
        answer += my_string[i];
    }
    return answer;
}