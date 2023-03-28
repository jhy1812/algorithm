#include <iostream>
#include <stdio.h>
#include <string>
#define _CRT_SECURE_NO_WARNINGS 
using namespace std;


int main()
{
	int a, b;
	while (true) {
		scanf("%d %d", &a, &b);
		if (a == 0 && b == 0) {
			break;
		}
		printf("%d\n", a + b);
	}
	return 0;
}