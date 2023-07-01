#include <iostream>
#include <vector>
#include <cstring>
#include <string>
using namespace std;

vector<pair<int, int>>v;
bool row[8];
bool col[8];
bool chess(int idx) {
	if (idx == v.size()) {
		return true;
	}
	int x = v[idx].first, y = v[idx].second;

	if (row[x] || col[y]) {
		return false;
	}
	row[x] = true;
	col[y] = true;

	chess(idx + 1);
}

int main() {
	int test = 0;
	cin >> test;

	for (int t = 1; t <= test; t++) {
		v.clear();
		memset(row, 0, sizeof(row));
		memset(col, 0, sizeof(col));
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				char c;
				cin >> c;
				if (c == 'O') {
					v.push_back({ i,j });
				}
			}
		}
		if (v.size() != 8) {
			cout << "#" << t << " " << "no" << "\n";
			continue;
		}
		string res = chess(0) ? "yes" : "no";
		cout << "#" << t << " " << res << "\n";
	}
}