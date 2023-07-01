#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int n;
int	arr[20][20];
bool visit[20];
priority_queue<int>pq;
void status() {
	vector<int>v1;
	vector<int>v2;
	int sum1 = 0, sum2 = 0;
	for (int i = 0; i < n; i++) {
		if (visit[i]) {
			v1.push_back(i);
		}
		else {
			v2.push_back(i);
		}
	}
	for (int i = 0; i < v1.size(); i++) {
		for (int j = 0; j < v1.size(); j++) {
			sum1 += arr[v1[i]][v1[j]];
		}
	}
	for (int i = 0; i < v2.size(); i++) {
		for (int j = 0; j < v2.size(); j++) {
			sum2 += arr[v2[i]][v2[j]];
		}
	}
	pq.push(-(abs(sum1-sum2)));

	return;
}

void startLink(int x, int c) {
	if (c == n/2) {
		status();
		return;
	}
	for (int i = x + 1; i < n; i++) {
		visit[i] = true;
		startLink(i, c+1);
		visit[i] = false;
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		vector<int>v;
		visit[i] = true;
		startLink(0, 1);
	}
	cout << -pq.top();
}