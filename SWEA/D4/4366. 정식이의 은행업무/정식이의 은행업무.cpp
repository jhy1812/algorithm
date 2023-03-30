#include <iostream>
#include <string>

using namespace std;

int T;
long long sib2, sib3, result;
string num2, num3;
long long result2[100];
long long result3[100];

int main()
{
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> num2;
		cin >> num3;
		sib2 = 0;
		sib3 = 0;
		int leng2 = num2.length();
		int leng3 = num3.length();
		int flag = 0;
		for (int i = 0; i < leng2; i++) {
			sib2 += (num2[i] - '0')*(1 << (leng2 - i - 1));
		}

		for (int i = 0; i < leng3; i++) {
			long long tmp = 1;
			for (int j = leng3 - i - 1; j > 0; j--) {
				tmp = tmp * 3;
			}
			sib3 += (num3[i] - '0')*tmp;
		}
		for (int i = 0; i < leng2; i++) {
			if (num2[i] == '0') {
				sib2 += (1 << (leng2 - i - 1));
				result2[i] = sib2;
				sib2 -= (1 << (leng2 - i - 1));
			}
			else {
				sib2 -= (1 << (leng2 - i - 1));
				result2[i] = sib2;
				sib2 += (1 << (leng2 - i - 1));
			}
		}
		for (int i = 0; i < leng3; i++) {
			long long tmp = 1;
			for (int j = leng3 - i - 1; j > 0; j--) {
				tmp = tmp * 3;
			}
			if (num3[i] == '0') {
				result3[i] = sib3 + tmp;
				result3[leng3 + i] = sib3 + tmp * 2;
			}
			else if (num3[i] == '1') {
				result3[i] = sib3 - tmp;
				result3[leng3 + i] = sib3 + tmp;
			}
			else {
				result3[i] = sib3 - tmp;
				result3[leng3 + i] = sib3 - tmp * 2;
			}
		}

		for (int i = 0; i < leng2; i++) {
			for (int j = 0; j < leng3 * 2; j++) {
				if (result2[i] == result3[j]) {
					result = result2[i];
					flag = 1;
					break;
				}
			}
			if (flag == 1) {
				break;
			}
		}

		cout << "#" << tc << " " << result << "\n";
	}

	return 0;
}