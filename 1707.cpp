#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;


int k;
int v, e;

int main() {

	cin >> k;

	for (int t = 0; t < k; t++) {
		cin >> v >> e;
		vector<int> node[20001];
		for (int s = 0; s < e; s++) {
			int n1, n2;
			cin >> n1 >> n2;
			node[n1].push_back(n2);
			node[n2].push_back(n1);
		}
		bool f = false;

		for (int i = 1; i <= v; i++) {
			queue<pair<int , pair<int, int>>>qq;
			qq.push({ i, { i, 0 } });

			while (!qq.empty()) {
				int now = qq.front().second.first;
				int cnt = qq.front().second.second;
				int prev = qq.front().first;
				qq.pop();
				if (cnt > 3) break;

				for (int j = 0; j < node[i].size(); j++) {
					if (prev == node[i][j]) continue;
					if (node[i][j] == i) {
						f = true;
						break;
					}
					qq.push({ now, {node[i][j], cnt + 1} });
				}
				
			}
			if (f) {
				break;
			}
		}

		if (f) {
			cout << "NO"<<"\n";
		}
		else {
			cout << "YES"<<"\n";
		}
	}

}