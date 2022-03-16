#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n, k, a, total=0;
	string str;
	cin >> n >> k;
	queue<int> q[21];
	int *student = new int[n];
	for (int i = 1; i < n+1; i++) {
		cin >> str;
		q[str.length()].push(i);
		student[i] = 1;
	}

	cout << total;

}