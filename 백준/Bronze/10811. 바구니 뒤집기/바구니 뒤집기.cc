#include <iostream>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, a, b, tmp;
	int arr[101] = { 0, };
	for (int i = 1; i < 101; i++) {
		arr[i] = i;
	}
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		for (int j = 0; j < (b - a + 1) / 2; j++) {
			tmp = arr[a+j];
			arr[a + j] = arr[b - j];
			arr[b - j] = tmp;
		}
	}
	for (int i = 1; i < N + 1; i++) {
		cout << arr[i] << " ";
	}
	return 0;
}