#include <iostream>
#include <string>
using namespace std;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int R;
		string S;
		cin >> R >> S;
		int leng = S.size();
		for (int j = 0; j < leng; j++) {
			for (int k = 0; k < R; k++) {
				cout << S[j];
			}
		}
		cout << "\n";
	}
	return 0;
}