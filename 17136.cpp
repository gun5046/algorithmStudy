
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

void recur(int cnt) {	//cnt�� �����̸�  ���̴� ����
	if (result < cnt) {	//���� ���
		return;
	}

	if (fill_check()) {	//���̿� ��� 0���� ������ �� true ��ȯ
		if (result > cnt) result = cnt;	//�ּҰ� ����
		return;
	}

	for (int i = 0; i < 10; i++) {
		for (int k = 0; k < 10; k++) {
			if (map[i][k] == 1) {
				for (int j = 4; j >= 0; j--) {	//������ũ�� j
					if (paper[j] > 0 && check(i, k, j) && range_check(i + j, k + j)) {
						paper[j]--;
						fill(i, k, j, 0);	//�����̰� �� �� �ִٸ� 0���� ä��°���

						recur(cnt + 1);

						paper[j]++;
						fill(i, k, j, 1);

					}
				}
				return;
				//������ �����̸� �ٴ��� ��Ų �ķδ� ���̻� �ݺ��� �� �ʿ����
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

	recur(0);	//�����̸� ���̴� ����

	//�Լ� ȣ�� ���� = �����̸� ���̴� ����

	cout << (result == 100 ? -1 : result);
}