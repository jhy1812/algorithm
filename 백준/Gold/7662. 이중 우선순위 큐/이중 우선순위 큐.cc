#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>

int T, n, len, maxx, minn;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::cin >> T;

    for (int i = 0; i < T; i++) {
        std::cin >> n;
        std::priority_queue<int, std::vector<int>> maxq;
        std::priority_queue<int, std::vector<int>, std::greater<int>> minq;
        std::map<int, int> check;

        len = 0;
        for (int i = 0; i < n; i++) {
            char order;
            int num;
            std::cin >> order >> num;
            if (order == 'I') {
                maxq.push(num);
                minq.push(num);
                len++;
                check[num]++;
            }
            else {
                if (len == 0) {
                    continue;
                }
                len--;
                if (num == -1) {
                    while (minq.size() > 0) {
                        int tmp = minq.top();
                        if (check[tmp] > 0) {
                            break;
                        }
                        minq.pop();
                    }
                    int tmp = minq.top();
                    check[tmp]--;
                    minq.pop();
                }
                else {
                    while (maxq.size() > 0) {
                        int tmp = maxq.top();
                        if (check[tmp] > 0) {
                            break;
                        }
                        maxq.pop();
                    }
                    int tmp = maxq.top();
                    check[tmp]--;
                    maxq.pop();
                }
            }
        }
        if (len == 0) {
            std::cout << "EMPTY" << "\n";
        }
        else {
            int maxx = 0;
            int minn = 0;

            while (minq.size() > 0) {
                int tmp = minq.top();
                if (check[tmp] > 0) {
                    break;
                }
                minq.pop();
            }

            while (maxq.size() > 0) {
                int tmp = maxq.top();
                if (check[tmp] > 0) {
                    break;
                }
                maxq.pop();
            }
            std::cout << maxq.top() << " " << minq.top() << "\n";
        }
    }

    return 0;
}