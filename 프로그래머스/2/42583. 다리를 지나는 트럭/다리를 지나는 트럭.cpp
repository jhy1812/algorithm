#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int count = 0;
    int bt = 0;
    int tw = 0;
    int sec = 1;
    queue<pair<int, int>> q;
    
    while(true) {
        if (count >= truck_weights.size()) {
            sec = max(sec, q.front().second + bridge_length);
            q.pop();
            if (q.size() == 0) {
                break;
            }
        }
        else if (q.size() == 0) {
            q.push(make_pair(truck_weights[count], sec));
            tw += truck_weights[count];
            sec++;
            count++;
        }
        else {
            if (tw + truck_weights[count] > weight || q.size() >= bridge_length) {
                int tmp = q.front().first;
                sec = max(sec, q.front().second + bridge_length);
                tw -= tmp;
                q.pop();
            }
            else {
                q.push(make_pair(truck_weights[count], sec));
                tw += truck_weights[count];
                count++;
                sec++;
            }
        }
    }
    
    return sec;
}