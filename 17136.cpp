
#include<iostream>

using namespace std;

int map[10][10];
int paper[5] = { 5, 5, 5, 5, 5 };
int result = 100;

bool check(int i, int k, int j) {
	for (int x = i; x <= i + j; x++) {
		for (int y = k; y <= k + j; y++) {

			if (map[x][y] == 0) {

				return false;
			}
		}
	}
	return true;
}

void fill(int i, int k, int j, int v) {
	for (int x = i; x <= i + j; x++) {
		for (int y = k; y <= k + j; y++) {
			map[x][y] = v;
		}
	}
}

bool fill_check() {
	for (int i = 0; i < 10; i++) {
		for (int k = 0; k < 10; k++) {
			if (map[i][k] == 1) return false;
		}
	}
	return true;
}

bool range_check(int x, int y) {
	if (x < 10 && y < 10) return true;
	return false;
}

void recur(int cnt) {	//cnt가 색종이를  붙이는 개수
	if (result < cnt) {	//기저 사례
		return;
	}

	if (fill_check()) {	//종이에 모두 0으로 되있을 시 true 반환
		if (result > cnt) result = cnt;	//최소값 저장
		return;
	}

	for (int i = 0; i < 10; i++) {
		for (int k = 0; k < 10; k++) {
			if (map[i][k] == 1) {
				for (int j = 4; j >= 0; j--) {	//색종이크기 j
					if (paper[j] > 0 && check(i, k, j) && range_check(i + j, k + j)) {
						paper[j]--;
						fill(i, k, j, 0);	//색종이가 들어갈 수 있다면 0으로 채우는거죠

						recur(cnt + 1);

						paper[j]++;
						fill(i, k, j, 1);

					}
				}
				return;
				//어차피 색종이를 다대입 시킨 후로는 더이상 반복문 돌 필요없음
			}
		}
	}
}

int main() {
	for (int i = 0; i < 10; i++) {
		for (int k = 0; k < 10; k++) {
			cin >> map[i][k];
		}
	}

	recur(0);	//색종이를 붙이는 갯수

	//함수 호출 개수 = 색종이를 붙이는 갯수

	cout << (result == 100 ? -1 : result);
}