#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <cstring>

using namespace std;

int ans;
string str;
int c;
void dfs(int idx, int change) {

	if (change == c) {
		if (ans < stoi(str)) {
			ans = stoi(str);
		}
		return;
	}

	for (int i = idx; i < str.size() - 1; i++) {
		for (int j = i + 1; j < str.size(); j++) {
			swap(str[i], str[j]);
			dfs(i, change + 1);
			swap(str[i], str[j]);
		}
	}
}

int main() {
	int test;
	cin >> test;

	for (int t = 1; t <= test; t++) {
		ans = 0;
		cin >> str;
		cin >> c;

		if (c > str.size()) {
			if (c % 2 == 1) {
				c = str.size() - 1;
			}
			else {
				c = str.size();
			}
		}

		dfs(0, 0);
		cout << "#" << t << " " << ans << "\n";
	}
}