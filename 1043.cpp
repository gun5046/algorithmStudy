#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <deque>
#include <list>
#include <string>
#include <cstring>
#include <sstream>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <math.h>

using namespace std;

int n, m;
int c, p;
vector<int> tr_list;
bool tr[51];
vector<int>pt[51];
queue<int>q;
bool check_pt[51];
vector<int>member[51];
int main() {
	cin >> n >> m;

	cin >> c;

	for (int i = 0; i < c; i++) {
		int num;
		cin >> num;
		tr_list.push_back(num);
		tr[num] = true;
	}

	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		for (int j = 0; j < num; j++) {
			int num1;
			cin >> num1;
			pt[i].push_back(num1);
			member[num1].push_back(i);
			if (tr[num1]) {
				q.push(i);
				check_pt[i] = true;
			}
		}
	}

	while (!q.empty()) {
		int party = q.front();
		q.pop();

		for (int i = 0; i < pt[party].size(); i++) {
			int mb = pt[party][i];
			for (int j = 0; j < member[mb].size(); j++) {
				int next = member[mb][j];
				if (check_pt[next]) continue;
				check_pt[next] = true;
				q.push(next);
			}
			
		}
	}

	int result = 0;
	for (int i = 0; i < m; i++) {
		if (!check_pt[i]) {
			result++;
		}
	}
	cout << result;

}