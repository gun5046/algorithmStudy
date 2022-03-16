#include <iostream>
#include <cstring>

using namespace std;

int n, m;
int arr[9];
bool visited[9];

void process(int cnt, int c) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
	}
	else {
		for (int i = c+1; i <= n; i++) {
			if (!visited[i]) {
				visited[i] = true;
			
				arr[cnt] = i;
				process(cnt+1, arr[cnt]);
				visited[i] = false;
				
			}
		}
	}
}

int main() {
	cin >> n >> m;
	memset(arr, 0, sizeof(int) * 9);
	memset(visited, 0, sizeof(bool) * 9);
	process(0,0);
}