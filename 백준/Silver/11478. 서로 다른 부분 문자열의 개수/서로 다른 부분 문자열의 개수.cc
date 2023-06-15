#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
#include <string>

std::string s;
std::map<std::string, int>lst;

int main()
{
	std::cin >> s;

	for (int i = 0; i < int(s.size()); i++) {
		std::string now = "";
		for (int j = i; j<int(s.size()); j++) {
			now += s[j];
			lst[now]++;
		}
	}

	std::cout << int(lst.size());

	return 0;
}