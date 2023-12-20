#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

double result, credits;
std::map<std::string, double> score;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	score["A+"] = 4.5;
	score["A0"] = 4.0;
	score["B+"] = 3.5;
	score["B0"] = 3.0;
	score["C+"] = 2.5;
	score["C0"] = 2.0;
	score["D+"] = 1.5;
	score["D0"] = 1.0;
	score["F"] = 0.0;

	for (int i = 0; i < 20; i++) {
		std::string sub;
		double credit;
		std::string grade;
		std::cin >> sub >> credit >> grade;
		if (grade == "P") {
			continue;
		}
		result += score[grade] * credit;
		credits += credit;
	}
 
	std::cout << result / credits;

	return 0;
}