#include <iostream>
#include <algorithm>
#include <vector>

#define MIN 987654321;
using namespace std;

int paper[5] = { 0, 0, 0, 0, 0 };
int board[10][10];
int total=0;

void attach(int x, int y, int c) {
	if (x >= 10 || y >= 10) {

		return;
	}

	for (int i = x; i <= 9; i++) {
		for (int j = y; j <= 9; j++) {
			if (board[i][j] == 0) continue;
			//confirm(x, y);
		}
	}
}

void confirm(int x, int y) {

}

void explore() {

}

int main() {

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> board[i][j];
		}
	}

	attach(0, 0, 0);

	
}