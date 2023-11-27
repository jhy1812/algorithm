#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string s)
{
    int answer = 0;
    stack<char> st;
    
    for (int i = 0; i < s.size(); i++) {
        if (st.size() == 0) {
            st.push(s[i]);
        }
        else if (st.top() == s[i]) {
            st.pop();
        }
        else {
            st.push(s[i]);
        }
    }
    
    if (st.size() == 0) {
        answer = 1;
    }
    
    return answer;
}