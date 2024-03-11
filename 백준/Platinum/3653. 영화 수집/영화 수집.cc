#include <iostream>
#include <vector>
#include <sstream>

int n, m, result;
std::vector<int> I;
std::vector<int> segment;

int make_tree(int st, int ed, int idx) {
    if (ed <= m) return segment[idx] = 0;

    if (st == ed) {
        I[st - m] = st;
        segment[idx] = 1;
        return segment[idx];
    }

    int mid = (st + ed) / 2;

    return segment[idx] = make_tree(st, mid, 2 * idx) + make_tree(mid + 1, ed, 2 * idx + 1);
}

int get_result(int st, int ed, int idx, int left, int right, int val) {
    if (right < st || ed < left) return segment[idx];

    if (left < st && ed < right) {
        result += segment[idx];
        return segment[idx];
    }

    if (st == ed) {
        if (st == right) return segment[idx] = 0;
        else {
            I[val] = st;
            return segment[idx] = 1;
        }
    }

    int mid = (st + ed) / 2;
    return segment[idx] = get_result(st, mid, 2 * idx, left, right, val) + get_result(mid + 1, ed, 2 * idx + 1, left, right, val);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    int T;
    std::cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        std::cin >> n >> m;

        I.resize(100001);
        segment.resize(800000);

        make_tree(1, n + m, 1);

        for (int i = 0; i < m; i++) {
            result = 0;
            int tar;
            std::cin >> tar;
            get_result(1, n + m, 1, m - i, I[tar], tar);
            std::cout << result << " ";
        }

        std::cout << "\n";
    }

    return 0;
}
