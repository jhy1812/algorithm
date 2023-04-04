#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int maxx;
string A, B;


int main()
{
	cin >> A;
	cin >> B;
	int lenga = int(A.size());
	int lengb = int(B.size());

	vector<vector<int>>arr(lengb, vector<int>(lenga));
	
	if (A[0] == B[0]) {
		arr[0][0] = 1;
		maxx = 1;
	}

	for (int i = 1; i < lenga; i++) {
		if (B[0] == A[i]) {
			arr[0][i] = 1;
		}
		else {
			arr[0][i] = arr[0][i - 1];
		}
		if (arr[0][i] > maxx) {
			maxx = arr[0][i];
		}
	}

	for (int i = 1; i < lengb; i++) {
		if (B[i] == A[0]) {
			arr[i][0] = 1;
		}
		else {
			arr[i][0] = arr[i-1][0];
		}
		if (arr[i][0] > maxx) {
			maxx = arr[i][0];
		}
	}

	for (int i = 1; i < lengb; i++) {
		for (int j = 1; j < lenga; j++) {
			if (B[i] == A[j]) {
				arr[i][j] = arr[i - 1][j - 1] + 1;
			}
			else {
				arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
			}
			maxx = max(arr[i][j], maxx);
		}
	}

	cout << maxx;

	return 0;
}