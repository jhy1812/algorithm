#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct point {
	int x;
	int y;
	int z;
	int num;
};

struct tunnel {
	int num1;
	int num2;
	int leng;
};

int N, a, b, c, cnt, summ;
int boss[100000];

bool cmpx(point a, point b) {
	return a.x < b.x;
}

bool cmpy(point a, point b) {
	return a.y < b.y;
}

bool cmpz(point a, point b) {
	return a.z < b.z;
}

bool cmpl(tunnel a, tunnel b) {
	return a.leng < b.leng;
}

int findboss(int a) {
	if (boss[a] == -1) {
		return a;
	}
	int ret = findboss(boss[a]);
	boss[a] = ret;
	return ret;
}

void un(int a, int b) {
	int fa = findboss(a);
	int fb = findboss(b);
	if (fa == fb) {
		return;
	}
	boss[fb] = fa;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<point>arr;
	vector<tunnel>connect;

	cin >> N;

	for (int i = 0; i < N; i++) {
		boss[i] = -1;
	}
	
	for (int i = 0; i < N; i++) {
		cin >> a >> b >> c;
		point tmp;
		tmp.x = a;
		tmp.y = b;
		tmp.z = c;
		tmp.num = i;
		arr.push_back(tmp);
	}
	
	sort(arr.begin(), arr.end(), cmpx);

	for (int i = 1; i < N; i++) {
		tunnel tmp;
		tmp.num1 = arr[i - 1].num;
		tmp.num2 = arr[i].num;
		tmp.leng = arr[i].x - arr[i - 1].x;
		connect.push_back(tmp);
	}

	sort(arr.begin(), arr.end(), cmpy);

	for (int i = 1; i < N; i++) {
		tunnel tmp;
		tmp.num1 = arr[i - 1].num;
		tmp.num2 = arr[i].num;
		tmp.leng = arr[i].y - arr[i - 1].y;
		connect.push_back(tmp);
	}

	sort(arr.begin(), arr.end(), cmpz);

	for (int i = 1; i < N; i++) {
		tunnel tmp;
		tmp.num1 = arr[i - 1].num;
		tmp.num2 = arr[i].num;
		tmp.leng = arr[i].z - arr[i - 1].z;
		connect.push_back(tmp);
	}

	sort(connect.begin(), connect.end(), cmpl);

	for (int i = 0; i<int(connect.size()); i++) {
		if (findboss(connect[i].num1) != findboss(connect[i].num2)) {
			un(connect[i].num1, connect[i].num2);
			cnt += 1;
			summ += connect[i].leng;
		}
		if (cnt == N - 1) {
			break;
		}
	}

	cout << summ;

	return 0;
}