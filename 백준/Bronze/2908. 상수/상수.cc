#include <iostream>
#include <string>
using namespace std;

int main()
{
	string num1, num2;
	cin >> num1 >> num2;
	int rnum1 = (num1[2] - '0') * 100 + (num1[1]-'0')*10 +num1[0]-'0';
	int rnum2 = (num2[2] - '0') * 100 + (num2[1] - '0') * 10 + num2[0] - '0';

	if (rnum1 > rnum2) {
		cout << rnum1;
	}
	else {
		cout << rnum2;
	}
	return 0;
}