#include <iostream>
#include <algorithm>
#include <vector>

int N, le, ri;
long long ret;
std::vector<long long> arr(1);

long long get_result(int st, int ed) {
	if (st == ed) {
		if (ret < arr[st] * arr[st]) {
			ret = arr[st] * arr[st];
			le = st;
			ri = ed;
		}
		return arr[st] * arr[st];
	}

	int mid = (st + ed) / 2;
	long long result = get_result(st, mid);
	long long rn = get_result(mid + 1, ed);
	if (ret < result) {
		ret = result;
		le = st;
		ri = mid;
	}
	if (result <= rn) {
		result = rn;
	}

	if (ret < rn) {
		ret = rn;
		le = mid + 1;
		ri = ed;
	}

	int l = mid;
	int r = mid + 1;
	long long Sum = arr[mid] + arr[mid + 1];
	long long Min = std::min(arr[mid], arr[mid + 1]);
	result = std::max(result, Sum * Min);
	if (ret < Sum * Min) {
		ret = Sum * Min;
		le = l;
		ri = r;
	}
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
		if (ret < Sum * Min) {
			ret = Sum * Min;
			le = l;
			ri = r;
		}
	}



	return result;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;

	ret = -1;

	for (int i = 0; i < N; i++) {
		long long tmp;
		std::cin >> tmp;
		arr.push_back(tmp);
	}

	std::cout << get_result(1, N) << "\n";
	std::cout << le << " " << ri;
	return 0;
}