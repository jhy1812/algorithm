#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct point {			// 행성 좌표 입력할 구조체
	int x;
	int y;
	int z;
	int num;
};

struct tunnel {			// 행성 간의 거리 구할 구조체
	int num1;
	int num2;
	int leng;
};

int N, a, b, c, cnt, summ;		// N - 행성 수, (a, b, c) - 행성 좌표 받을 변수, cnt - 연결 수, summ - 터널 길이 합
int boss[100000];				// 묶여있는 행성 번호 표시할 배열

bool cmpx(point a, point b) {	// x 좌표 기준 오름차순 정렬해줄 함수
	return a.x < b.x;
}

bool cmpy(point a, point b) {	// y 좌표 기준 오름차순 정렬해줄 함수
	return a.y < b.y;
}

bool cmpz(point a, point b) {	// z 좌표 기준 오름차순 정렬해줄 함수
	return a.z < b.z;
}

bool cmpl(tunnel a, tunnel b) {	// 터널 길이 기준 오름차순 정렬해줄 함수
	return a.leng < b.leng;
}

int findboss(int a) {			// 각 행성이 어떤 행성과 묶여있는지 찾아줄 함수
	if (boss[a] == -1) {		// 묶인 행성 없으면 본인 반환
		return a;
	}
	int ret = findboss(boss[a]);	// 묶인 행성 있으면 해당 행성 찾아서 반환
	boss[a] = ret;
	return ret;
}

void un(int a, int b) {				// 두 행성 묶어줄 함수
	int fa = findboss(a);
	int fb = findboss(b);
	if (fa == fb) {					// 이미 묶여있으면 그냥 리턴
		return;
	}
	boss[fb] = fa;					// 아니면 묶어줌
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<point>arr;				// 행성 좌표 및 번호 저장할 벡터
	vector<tunnel>connect;			// 행성간 거리 저장할 벡터

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
	
	sort(arr.begin(), arr.end(), cmpx);			// 행성 x 좌표 기준 오름차순 정렬

	for (int i = 1; i < N; i++) {
		tunnel tmp;
		tmp.num1 = arr[i - 1].num;
		tmp.num2 = arr[i].num;
		tmp.leng = arr[i].x - arr[i - 1].x;	
		connect.push_back(tmp);					// 정렬 후 가까운 행성끼리의 거리 정보 저장 
	}

	sort(arr.begin(), arr.end(), cmpy);			// y 좌표 기준 오름차순 정렬 후 위와 동일

	for (int i = 1; i < N; i++) {
		tunnel tmp;
		tmp.num1 = arr[i - 1].num;
		tmp.num2 = arr[i].num;
		tmp.leng = arr[i].y - arr[i - 1].y;
		connect.push_back(tmp);
	}

	sort(arr.begin(), arr.end(), cmpz);			// z 좌표 기준 오름차순 정렬 후 위와 동일

	for (int i = 1; i < N; i++) {
		tunnel tmp;
		tmp.num1 = arr[i - 1].num;
		tmp.num2 = arr[i].num;
		tmp.leng = arr[i].z - arr[i - 1].z;
		connect.push_back(tmp);
	}
	
	sort(connect.begin(), connect.end(), cmpl);			// 행성간 거리 기준으로 정렬

	for (int i = 0; i<int(connect.size()); i++) {
		if (findboss(connect[i].num1) != findboss(connect[i].num2)) {		// 두행성 연결되지 않았으면
			un(connect[i].num1, connect[i].num2);							// 연결
			cnt += 1;														// 연결 수 +1
			summ += connect[i].leng;										// 거리합 갱신
		}
		if (cnt == N - 1) {													// 연결 수 N-1이면 스탑
			break;
		}
	}

	cout << summ;

	return 0;
}