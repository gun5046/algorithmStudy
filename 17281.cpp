#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <algorithm>
#include <utility>
#include <cstring>
#include <string>
#include <sstream>
#include <math.h>
#include <list>
#include <deque>
#include <vector>

using namespace std;

int n;
int arr[51][10];
int order[10];
int max_score = 0;
void gaming(int inning, int first, int score) {
	if (inning > n) {
		max_score = max(score, max_score);
		return;
	}
	int out = 0;
	bool runner[3] = { false, };
	int now = first;  //order[now] 가 타자번호
	while (out != 3) {
		if (now == 10) {
			now = 1;
		}
		if (arr[inning][order[now]] == 0) {
			out++;
		}
		else if (arr[inning][order[now]] == 1) {
			if (runner[2]) {
				score++;
				runner[2] = false;
			}
			if (runner[1]) {
				runner[2] = true;
				runner[1] = false;
			}
			if (runner[0]) {
				runner[1] = true;
				runner[0] = false;
			}
			runner[0] = true;
		}
		else if (arr[inning][order[now]] == 2) {
			if (runner[2]) {
				score++;
				runner[2] = false;
			}
			if (runner[1]) {
				score++;
				runner[1] = false;
			}
			if (runner[0]) {
				runner[2] = true;
				runner[0] = false;
			}
			runner[1] = true;
		}
		else if (arr[inning][order[now]] == 3) {
			if (runner[2]) {
				score++;
				runner[2] = false;
			}
			if (runner[1]) {
				score++;
				runner[1] = false;
			}
			if (runner[0]) {
				score++;
				runner[0] = false;
			}
			runner[2] = true;
		}
		else {
			if (runner[2]) {
				score++;
				runner[2] = false;
			}
			if (runner[1]) {
				score++;
				runner[1] = false;
			}
			if (runner[0]) {
				score++;
				runner[0] = false;
			}
			score++;
		}
		now++;
	}
	gaming(inning + 1, now, score);
}

void gameStart() {
	vector<int> temp = {2,3,4,5,6,7,8,9};
	order[4] = 1;
	do {
		
		for (int i = 1, j = 0; j < temp.size(); i++) {
			if (i == 4) continue;
 			order[i] = temp[j++];
		}

		gaming(1, 1, 0);
	} while (next_permutation(temp.begin(), temp.end()));
}

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 9; j++) {
			int num;
			cin >> num;
			arr[i][j] = num;
		}
	}

	gameStart();

	cout << max_score;
}