#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int n, k;
int num[100001] = { 0, };
queue <int> q;
bool visited[100001] = { false, };
int cnt=0;

void findSister() {
	q.push(n);
	visited[n]=true;

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		//x-1, 2*x, x+1
		if (now - 1 >= 0) {
			if (!visited[now - 1]) {
				q.push(now - 1);
				visited[now - 1]=true;
				num[now - 1] = num[now]+1;
			}
			else {
				if (num[now - 1] > num[now] + 1) {
					q.push(now - 1);
					num[now - 1] = num[now] + 1;
				}
			}
		}
		if (now + 1 <= 100000) {
			if (!visited[now + 1]) {
				q.push(now + 1);
				visited[now + 1] = true;
				num[now + 1] = num[now] + 1;
			}
			else {
				if (num[now + 1] > num[now] + 1) {
					q.push(now + 1);
					num[now + 1] = num[now] + 1;
				}
			}
		}
		if (now * 2 <= 100000) {
			if (!visited[now * 2]) {
				q.push(2 * now);
				visited[2 * now] = true;
				num[now * 2] = num[now] + 1;
			}
			else {
				if (num[now * 2] > num[now] + 1) {
					q.push(now * 2);
					num[now * 2] = num[now] + 1;
				}
			}
		}
		
	}
	cout << num[k];
}

int main() {
	cin >> n >> k;

	findSister();
}