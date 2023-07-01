#include <iostream>
#include <cstring>
using namespace std;

int n;

int col[15];
int total = 0;

bool check(int y) {

	for (int i = 0; i < y; i++) {
		if (col[i] == col[y] || abs(col[i] - col[y]) == abs(i - y)) {
			return false;
		}
	}
	return true;
}

void nqueen(int x) {
	if (x == n) {
		total++;
	}
	else {
		for (int i = 0; i < n; i++) {
			col[x] = i;
			if (check(x)) {
				nqueen(x+1);
			}
		}
	}
}

int main() {

	cin >> n;

	nqueen(0);
	cout << total;
}