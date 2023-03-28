#include <iostream>
#include <string>
using namespace std;

int main()
{
	string S;
	getline(cin, S);
	int leng = S.length();
	int cnt = 0;
	for (int i = 0; i < leng; i++) {
		if (S.substr(i,1) == " " && i != leng-1 && i != 0) {
			cnt += 1;
		}
	}
	if (S == " ") {
		cout << 0;
	}
	else {
		cout << cnt+1;
	}

	return 0;
}