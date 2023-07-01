#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
int r, c;
char arr[500][10000];
char pipe[500][10000];
map<int, int>m;
int endp = 0;
void piperoad(int idx, int x, int y) {
	if (y == endp) {

	}
}

int main() {
	cin >> r >> c;

	for (int i = 0; i < r; i++) {
		m.insert({ r, 0 });
	}

	for (int i = 0; i < r; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < c; j++) {
			arr[i][j] = str[j];
			if (arr[i][j] == 'x') {
				m[j]++;
			}
		}
	}

	vector<pair<int, int>> v(m.begin(), m.end());
	sort(v.begin(), v.end(), [](pair<int, int>a, pair<int, int> b) {
		if (a.second == b.second) {
			return a.first > b.first;
		}
		else {
			return a.second < b.second;
		}
		});
	

	for (int i = 0; i < v.size(); i++) {
		int col = v[i].first;
		for (int j = 0; j < c; j++) {
			pipe[col][j] = arr[col][j];
		}
	}

	//pipemap(0, 0, 0);

}