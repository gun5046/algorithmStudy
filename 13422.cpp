#include <deque>
#include <vector>
#include <algorithm>
#include <iostream>
#include <utility>

using namespace std;

int t;
int n; int k; int m;
class Circular {
public :
	int front;
	int v;

	Circular(int f, int v) {
		this->front = f;
		this->v = v;
	}
	Circular() {
	}
};
int main() {
	cin >> t;
	for (int test = 0; test < t; test++) {
		cin >> n >> m >> k;
		Circular circle[100000];
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			if (i == n - 1) {
				circle[i] = Circular(0, num);
			}
			else {
				circle[i] = Circular(i + 1, num);
			}
		}

		int sum = 0;
		int cnt = 0;
		for (int i = 0; i < m; i++) {
			sum += circle[i].v;
		}
		if (sum < k) {
			cnt++;
		}
		if (n == m) {
			cout << cnt;
		}
		else {

			for (int i = circle[m - 1].front, j = 0; j < n - 1; i = circle[i].front, j++) {
				sum = sum + circle[i].v - circle[j].v;
				if (sum < k) {
					cnt++;
				}
			}

			cout << cnt << "\n";
		}
	}
}