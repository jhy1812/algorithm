#include <iostream>
#include <stack>
#include <deque>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::stack<int> st;
    std::deque<std::string> q;

    int N;
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        int order;
        std::cin >> order;

        if (order == 1) {
            std::string tmp;
            std::cin >> tmp;
            q.push_back(tmp);
            st.push(1);
        } else if (order == 2) {
            std::string tmp;
            std::cin >> tmp;
            q.push_front(tmp);
            st.push(2);
        } else {
            if (q.size() == 0) {
                continue;
            } else {
                int last = st.top();
                st.pop();
                if (last == 1) {
                    q.pop_back();
                } else if (last == 2) {
                    q.pop_front();
                }
            }
        }
    }

    int leng = q.size();
    std::string result = "";

    for (int i = 0; i < leng; i++) {
        result += q.front();
        q.pop_front();
    }
    if (result == "") {
        std::cout << 0;
    }
    else {
        std::cout << result;
    }

    return 0;
}
