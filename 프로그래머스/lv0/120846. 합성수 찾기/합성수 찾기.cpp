#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    vector<int>arr(n+1, 0);
    int cnt = 0;
    for (int i =2; i<int(sqrt(n))+1;i++){
        if (arr[i] == 1){
            continue;
        }
        for (int j = 2*i; j<=n; j+=i){
            arr[j] = 1;
        }
    }
    for (int i = 1; i<=n; i++){
        if(arr[i] == 0){
            cnt += 1;
        }
    }
    int answer = n - cnt;
    return answer;
}