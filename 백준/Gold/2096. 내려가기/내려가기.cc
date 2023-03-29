#include <iostream>
#include <string>
#include <queue>

using namespace std;



int dy[3] = {1, 1, 1};
int dx[3] = {-1, 0, 1};
int N, maxx, minn, joa, o;
int arr[100000][3] = { 0, };
int dp[2][3] = { 0, };

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	maxx = 0;
	minn = 5e8;
	joa = 0;
	o = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[i][j];
		}
	}
	dp[0][0] = arr[0][0];
	dp[0][1] = arr[0][1];
	dp[0][2] = arr[0][2];
	for (int i = 1; i < N; i++) {
		joa = max(dp[(i - 1)%2][0], dp[(i - 1)%2][1]);
		o = max(dp[(i - 1)%2][2], dp[(i - 1)%2][1]);
		dp[i%2][0] = joa + arr[i][0];
		dp[i%2][2] = o + arr[i][2];
		dp[i%2][1] = max(joa, o) + arr[i][1];
	}
	maxx = max(max(dp[(N - 1)%2][0], dp[(N - 1)%2][1]), dp[(N - 1)%2][2]);
	dp[0][0] = arr[0][0];
	dp[0][1] = arr[0][1];
	dp[0][2] = arr[0][2];
	for (int i = 1; i < N; i++) {
		joa = min(dp[(i - 1) % 2][0], dp[(i - 1) % 2][1]);
		o = min(dp[(i - 1) % 2][2], dp[(i - 1) % 2][1]);
		dp[i % 2][0] = joa + arr[i][0];
		dp[i % 2][2] = o + arr[i][2];
		dp[i % 2][1] = min(joa, o) + arr[i][1];
	}
	minn = min(min(dp[(N - 1) % 2][0], dp[(N - 1) % 2][1]), dp[(N - 1) % 2][2]);
		
	cout << maxx << " " << minn;
	return 0;
}

