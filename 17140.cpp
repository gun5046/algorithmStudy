#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

int r, c, k;
int r1, c1;
int arr[101][101];
bool cmp(pair<int,int> a, pair<int,int> b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	else {
		return a.second < b.second;
	}
}

void sortArray() {
	if (r1 >= c1) {
		int a[101][101] = { 0, };
		vector<int>v[101];
		int max_size=0;
		for (int i = 1; i <= r1; i++) {
			map<int, int> m;

			for (int j = 1; j <= c1; j++) {
				int num = arr[i][j];
				if (num == 0) continue;
				if (m.find(num) == m.end()) {
					m.insert({ num, 1 });
				}
				else {
					m[num]++;
				}
			}
			
			vector < pair<int, int>>temp(m.begin(), m.end());
			sort(temp.begin(), temp.end(), cmp);
			
			for (int j = 0; j < temp.size(); j++) {
				v[i].push_back(temp[j].first);
				v[i].push_back(temp[j].second);
			}
			if (v[i].size() > max_size) max_size = v[i].size();

		}
		c1 = max_size;
		for (int i = 1; i <= r1; i++) {
			int idx = 1;
			for (int j = 0; j < v[i].size(); j++) {
				arr[i][idx++] = v[i][j];
			}
			for (idx; idx <= max_size; idx++) {
				arr[i][idx] = 0;
			}
		}

	}
	else {
		int a[101][101] = { 0, };
		vector<int>v[101];
		int max_size = 0;
		for (int i = 1; i <= c1; i++) {
			map<int, int> m;

			for (int j = 1; j <= r1; j++) {
				int num = arr[j][i];
				if (num == 0) continue;
				if (m.find(num) == m.end()) {
					m.insert({ num, 1 });
				}
				else {
					m[num]++;
				}
			}
			
			vector < pair<int, int>>temp(m.begin(), m.end());
			sort(temp.begin(), temp.end(), cmp);

			for (int j = 0; j < temp.size(); j++) {
				v[i].push_back(temp[j].first);
				v[i].push_back(temp[j].second);
			}
			if (v[i].size() > max_size) max_size = v[i].size();
		}
		r1 = max_size;
		for (int i = 1; i <= c1; i++) {
			int idx = 1;
			for (int j = 0; j < v[i].size(); j++) {
				arr[idx++][i] = v[i][j];
			}
			for (idx; idx <= max_size; idx++) {
				arr[idx][i] = 0;
			}
		}
	}
	
}
int main() {
	cin >> r >> c >> k;

	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> arr[i][j];
		}
	}
	r1 = 3;
	c1 = 3;
	int t = 0;
	while (t <= 100) {

		if (arr[r][c] == k) {
			cout << t;
			return 0;
		}
		
		sortArray();

		t++;
	}
	cout << -1;
}
///////////////////////2 1 3 1 1 2
// 3 1 1  3:1  1:2 - > 3 1 1 2 