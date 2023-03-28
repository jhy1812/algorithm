#include <iostream>
#include <stdio.h>
#include <string>
#define _CRT_SECURE_NO_WARNINGS 
using namespace std;


int main()
{
	int a, b;
	while (scanf("%d %d", &a, &b) != EOF) {
		printf("%d\n", a + b);
	}
	return 0;
}