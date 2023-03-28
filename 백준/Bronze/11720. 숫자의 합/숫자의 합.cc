#include <iostream>
#include <string>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, summ;
	string num;
	cin >> N;
	cin >> num;
	summ = 0;
	for (int i = 0; i < N; i++) {
		summ += num[i] - '0';
	}
	cout << summ;
}