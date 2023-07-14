#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <utility>
#include <algorithm>
#include <math.h>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <string>
#include <queue>
#include <stack>
#include <cstring>
#include <time.h>
#define INF 99999999
using namespace std;
int dis[100001];
int dx[2] = { -1,1 };
int main(){
	int n;
	int k;

	cin >> n;
	cin >> k;

	queue<int>q;

	for (int i = 0; i < 100001; i++) {
		dis[i] = INF;
	}
	q.push(n);
	dis[n] = 0;
	while (!q.empty()) {
		int loc = q.front();
		q.pop();
		if (loc == k) {
			cout << dis[loc];
			return 0;
		}
		for (int i = 0; i < 3; i++) {
			int nx;
			if (i==2) {
				nx = loc * 2;
				if (nx <= 0 || nx > 100000) continue;
				if (dis[nx] <= dis[loc]) continue;
				dis[nx] = dis[loc];

			}
			else {
				nx = loc + dx[i];

				if (nx <= 0 || nx > 100000) continue;
				if (dis[nx] <= dis[loc] + 1) continue;

				dis[nx] = dis[loc] + 1;
			}
			q.push(nx);
		}
	}
}