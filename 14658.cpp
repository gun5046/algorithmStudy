#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <list>
#include <deque>
#include <utility>
#include <algorithm>
#include <math.h>
#include <cstring>
#include <string>
#include <sstream>
#include <time.h>

using namespace std;

int n, m;
int l;
int k;
int result;
vector<int> dx;
vector<int> dy;
vector<pair<int, int>> star;

void countingStar(int x,int y, int side_x, int side_y) {
	int cnt = 0;
	for (int i = 0; i < k; i++) {
		int t_x = star[i].first, t_y = star[i].second;
		if (x <= t_x && t_x <= side_x && y <= t_y && t_y <= side_y) {
			cnt++;
		}
	}

	if (result < cnt) result = cnt;
}

void trampoline() {
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k; j++) {
			int x = star[i].first;
			int y = star[j].second;

			for (int t = 0; t < 4; t++) {
				int side_x = x + dx[t];
				int side_y = y + dy[t];

				countingStar(x, y, side_x, side_y);
			}
		}
	}
}

int main() {
	cin >> n >> m;

	cin >> l >> k;
	
	dx.push_back(l+1);
	dx.push_back(-l-1);
	dx.push_back(l+1);
	dx.push_back(-l-1);

	dy.push_back(l+1);
	dy.push_back(-l-1);
	dy.push_back(-l-1);
	dy.push_back(l+1);

	for (int i = 0; i < k; i++) {
		int x,y;

		cin >> x >> y;

		star.push_back({ x,y });
	}

	trampoline();

	cout << k-result;
}