#include <iostream>
#include <string>
using namespace std;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int bucket[26] = { 0, };
	string S;
	cin >> S;
	int leng = S.size();
	for (int i = 0; i < 26; i++) {
		bucket[i] = -1;
	}
	for (int i = leng - 1; i >= 0; i--) {
		bucket[int(S[i])-97] = i;
	}
	for (int i = 0; i < 26; i++) {
		cout << bucket[i] << " ";
	}
	return 0;
}