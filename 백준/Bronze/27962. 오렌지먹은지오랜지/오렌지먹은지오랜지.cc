#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n;
string arr;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	cin >> arr;
	int flag = 0;
	for (int leng = 1; leng<=n; leng++){
		int cnt = 0;
		for (int i = 0; i < leng; i++) {
			if (arr[i] != arr[n - leng + i]) {
				cnt += 1;
			}
		}
		if (cnt == 1) {
			flag = 1;
			break;
		}
	}
	if (flag == 0) {
		cout << "NO";
	}
	else {
		cout << "YES";
	}

	return 0;
}