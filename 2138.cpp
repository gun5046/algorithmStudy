#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#define INF 999999999
using namespace std;

int n;
bool light[100001];
bool target[100001];
int cnt = 0;
int res = INF;
void switchOn(int idx) {
	if (idx == 1) {
		light[idx] = !light[idx];
		light[idx + 1] = !light[idx + 1];
	}
	else if (idx == n) {
		light[idx] = !light[idx];
		light[idx - 1] = !light[idx - 1];
	}
	else {
		light[idx-1] = !light[idx-1];
		light[idx] = !light[idx];
		light[idx + 1] = !light[idx + 1];
	}
	cnt++;
	return;
}


int main() {
	cin >> n;
	
	string now;
	string tr;
	cin >> now;
	cin >> tr;
	for (int i = 0; i < n; i++) {
		light[i + 1] = now[i]-'0';
		target[i + 1] = tr[i]-'0';
	}
	
	int idx = 1;
	while (idx < n) {
		if (!(light[idx] ^ target[idx])) {
			idx++;
			continue;
		}

		switchOn(idx + 1);
		idx++;
	}

	if (!(light[n] ^ target[n])) res = min(res, cnt);

	for (int i = 0; i < n; i++) {
		light[i + 1] = now[i] - '0';
		target[i + 1] = tr[i] - '0';
	}

	switchOn(1);
	cnt = 1;
	idx = 1;
	while (idx < n) {
		if (!(light[idx] ^ target[idx])) {
			idx++;
			continue;
		}

		switchOn(idx + 1);
		idx++;
	}

	if (!(light[n] ^ target[n])) res = min(res, cnt);

	if (res == INF) cout << "-1";
	else cout << res;
}