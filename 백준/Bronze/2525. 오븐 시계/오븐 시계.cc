#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

int main() {
	int a, b, c, hour, minute;
	cin >> a >> b;
	cin >> c;
	hour = (a + (b + c) / 60)%24;
	minute = (b + c) % 60;
	printf("%d %d", hour, minute);
	return 0;
}