#include <iostream>
#include <string>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	string S;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> S;
		int leng = S.size();
		cout << S[0] << S[leng - 1] << "\n";
	}
}