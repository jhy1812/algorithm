#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

int N;
std::map<std::string, int> check;
std::vector<std::string> arr;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;
	
	for (int i = 0; i < N; i++) {
		std::string tmp;
		std::string ext = "";
		std::cin >> tmp;
		int flag = 0;

		for (int j = 0; j < tmp.size(); j++) {
			if (tmp[j] == '.') {
				flag = 1;
			}
			else if (flag) {
				ext += tmp[j];
			}
		}
		check[ext]++;
		if (check[ext] == 1) {
			arr.push_back(ext);
		}
	}

	std::sort(arr.begin(), arr.end());

	for (int i = 0; i < arr.size(); i++) {
		std::cout << arr[i] << " " << check[arr[i]] << "\n";
	}

	return 0;
}