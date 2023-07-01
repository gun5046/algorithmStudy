#include <iostream>
#include <vector>

using namespace std;

int n, m;
bool visit[9];

void nandm(int x, vector<int> v) {
	if (v.size() == m) {
		for (int num : v) {
			cout << num << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (visit[i]) continue;
		v.push_back(i);

		nandm(i, v);
		v.erase(v.end() - 1);

	}
}


int main() {
	cin >> n >> m;
	vector<int>v;
	for (int i = 1; i <= n; i++) {
		v.push_back(i);
		nandm(i, v);
		v.erase(v.begin());
	}
}