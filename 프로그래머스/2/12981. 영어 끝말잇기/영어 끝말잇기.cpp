#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    answer.push_back(0);
    answer.push_back(0);

    map<string, int> check;
    check[words[0]]++;
    for (int i = 1; i < words.size(); i++) {
        if (words[i-1][words[i-1].size() - 1] != words[i][0] || check[words[i]] == 1) {
            answer[0] = i % n + 1;
            answer[1] = i / n + 1;
            break;
        }
        check[words[i]]++;
    }

    return answer;
}