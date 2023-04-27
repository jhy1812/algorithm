#include <string>
#include <vector>

using namespace std;

string solution(vector<string> arr) {
    string answer = "";
    int l = int(arr.size());
    
    for (int i =0;i<l; i++){
        answer += arr[i];
    }
    return answer;
}