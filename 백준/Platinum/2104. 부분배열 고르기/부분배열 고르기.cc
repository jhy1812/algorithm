#include <iostream>
#include <algorithm>
#include <vector>

int N;
std::vector<long long> arr(1);

long long get_result(int st, int ed) {
	if (st == ed) {
		return arr[st] * arr[st];
	}

	int mid = (st + ed) / 2;
	long long result = std::max(get_result(st, mid), get_result(mid + 1, ed));
	int l = mid;
	int r = mid + 1;
	long long Sum = arr[mid] + arr[mid + 1];
	long long Min = std::min(arr[mid], arr[mid + 1]);
	result = std::max(result, Sum * Min);

	while (st < l || r < ed) {
		if (st < l && (r == ed || arr[l - 1] > arr[r + 1])) {
			Sum += arr[--l];
			Min = std::min(Min, arr[l]);
		}
		else if (arr[l - 1] == arr[r + 1]) {
			Sum += arr[--l] + arr[++r];
			Min = std::min(Min, arr[l]);
		}
		else {
			Sum += arr[++r];
			Min = std::min(Min, arr[r]);
		}
		result = std::max(result, Sum * Min);
	}

	return result;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;

	for (int i = 0; i < N; i++) {
		long long tmp;
		std::cin >> tmp;
		arr.push_back(tmp);
	}

	std::cout << get_result(1, N);

	return 0;
}